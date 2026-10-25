% step5_electrical_faults.m
% Simulates a DC motor with open/short-circuit faults, extracts features
% from armature current and speed, trains a classifier, tests on unseen runs.
clear; clc; rng(2);
here = fileparts(mfilename('fullpath'));
repo = fileparts(here);

dt = 1/12000;  fs = 1/dt;       % 12 kHz, same as the vibration detector
Tsim = 2.6; Tskip = 0.6;        % skip start-up transient
winLen = 2400;                  % 0.2 s windows
nRuns  = 40;                    % runs per class
classes = ["Healthy","OpenCircuit","ShortCircuit"];
tol = @() 1 + 0.08*(2*rand - 1);
n = round(Tsim/dt);

rows = {};  runID = 0;
for c = 1:3
    for r = 1:nRuns
        runID = runID + 1;
        Ra = 2.0*tol();  La = 2e-3*tol();  Ke = 0.1*tol();
        J  = 5e-4*tol(); B  = 1e-4*tol();
        Va = 18 + 12*rand;               % supply voltage (V)
        TL = 0.05 + 0.20*rand;           % load torque (N*m)
        k = 0;
        if c == 3, k = 0.10 + 0.20*rand; end   % fraction of turns shorted
        Ra = Ra*(1-k);  La = La*(1-k)^2;  Ke = Ke*(1-k);
        Tp = 0.08 + 0.07*rand;  Td = 0.01 + 0.02*rand;  ph = rand*Tp;

        i = zeros(n,1);  w = zeros(n,1);
        for s = 2:n
            t = (s-1)*dt;
            if c == 2 && mod(t+ph, Tp) < Td
                i(s) = 0;                                   % open circuit gap
            else
                i(s) = i(s-1) + dt*(Va - Ra*i(s-1) - Ke*w(s-1))/La;
            end
            w(s) = max(0, w(s-1) + dt*(Ke*i(s-1) - B*w(s-1) - TL)/J);
        end
        i = i + 0.02*randn(n,1);        % current sensor noise (A)
        w = w + 0.5*randn(n,1);         % speed sensor noise (rad/s)
        i = i(round(Tskip/dt)+1:end);
        w = w(round(Tskip/dt)+1:end);

        for q = 1:floor(numel(i)/winLen)
            idx = (q-1)*winLen+1 : q*winLen;
            ii = i(idx);  ww = w(idx);
            f = [mean(ii), std(ii), rms(ii), max(abs(ii)), kurtosis(ii), ...
                skewness(ii), max(abs(ii))/rms(ii), ...
                mean(ww), std(ww), mean(ww)/Va];
            rows{end+1,1} = [f, runID, c]; %#ok<SAGROW>
        end
    end
end

M = vertcat(rows{:});
names = ["i_mean","i_std","i_rms","i_peak","i_kurt","i_skew","i_crest", ...
    "w_mean","w_std","w_per_volt"];
T = array2table(M(:,1:10), 'VariableNames', cellstr(names));
T.RunID = M(:,11);
T.Label = categorical(M(:,12), 1:3, cellstr(classes));
fprintf('Windows per class:\n'); disp(groupsummary(T,'Label'))

% ---- Split by RUN (25% of runs per class to test)
[runIDs, ia] = unique(T.RunID);
runLabel = T.Label(ia);
cats = categories(T.Label);
testRuns = [];
for q = 1:numel(cats)
    rr = runIDs(runLabel == cats{q});
    testRuns = [testRuns; rr(randperm(numel(rr), round(0.25*numel(rr))))]; %#ok<AGROW>
end
isTest = ismember(T.RunID, testRuns);
pn = names(:)';
mdl = fitcensemble(T{~isTest,cellstr(pn)}, T.Label(~isTest), 'Method','Bag', ...
    'NumLearningCycles',50, 'Learners', templateTree('MaxNumSplits',40));
Yp  = predict(mdl, T{isTest,cellstr(pn)});
acc = mean(Yp == T.Label(isTest));
fprintf('Electrical-fault test accuracy: %.2f %% (%d test runs)\n', 100*acc, numel(testRuns));

fig = figure;
confusionchart(T.Label(isTest), Yp, 'Title', sprintf('Electrical faults, accuracy = %.1f %%', 100*acc));
exportgraphics(fig, fullfile(repo,'results','confusion_matrix_electrical.png'), 'Resolution',200);
save(fullfile(repo,'models','electricalModel.mat'), 'mdl', 'T');