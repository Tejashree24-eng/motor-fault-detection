% step7_mechanical_faults.m
% Simulated rotor vibration (Normal, Unbalance, Misalignment) -> features -> classifier.
clear; clc; rng(3);
here = fileparts(mfilename('fullpath'));
repo = fileparts(here);
addpath(here);

fs = 12000;  N = 4096;  nRuns = 40;  winPerRun = 6;
classes = ["Normal","Unbalance","Misalignment"];
tt = (0:N-1)'/fs;

rows = {};  runID = 0;
for c = 1:3
    for r = 1:nRuns
        runID = runID + 1;
        fr   = 20 + 30*rand;            % shaft speed 20-50 Hz (1200-3000 rpm)
        sev  = 0.5 + rand;              % fault severity
        gain = 0.8 + 0.4*rand;          % sensor / structure gain
        sig  = 0.03 + 0.03*rand;        % noise level (g)
        if c == 1
            a = [0.03 0.015 0.005];
        elseif c == 2
            a = [0.5*sev*(fr/35)^2, 0.03, 0.01];
        else
            a = [0.10*sev, 0.45*sev, 0.12*sev];
        end
        a = a*gain;
        for q = 1:winPerRun
            frq = fr*(1 + 0.003*randn);
            x = zeros(N,1);
            for k = 1:3
                x = x + a(k)*sin(2*pi*k*frq*tt + 2*pi*rand);
            end
            x = x + sig*randn(N,1) + 0.5*sig*filter(1,[1 -1.2 0.6],randn(N,1));
            f = mechFeatures(x, fs, frq);
            rows{end+1,1} = [f, runID, c, fr]; %#ok<SAGROW>
        end
    end
end

M = vertcat(rows{:});
names = ["std","rms","peak","kurt","crest","A1","A2","A3","A2_A1","A3_A1"];
T = array2table(M(:,1:10), 'VariableNames', cellstr(names));
T.RunID = M(:,11);
T.Label = categorical(M(:,12), 1:3, cellstr(classes));
T.Fr    = M(:,13);
disp(groupsummary(T,'Label'))
pn = cellstr(names);

%% Test 1: split by simulation run
[runIDs, ia] = unique(T.RunID);
runLabel = T.Label(ia);
cats = categories(T.Label);
testRuns = [];
for q = 1:numel(cats)
    rr = runIDs(runLabel == cats{q});
    testRuns = [testRuns; rr(randperm(numel(rr), round(0.25*numel(rr))))]; %#ok<AGROW>
end
isTest = ismember(T.RunID, testRuns);
tmpl = templateTree('MaxNumSplits',40);
mdl = fitcensemble(T{~isTest,pn}, T.Label(~isTest), 'Method','Bag', ...
    'NumLearningCycles',50, 'Learners', tmpl);
Yp  = predict(mdl, T{isTest,pn});
acc = mean(Yp == T.Label(isTest));
fprintf('Mechanical faults, split by run: %.2f %% (%d test runs)\n', 100*acc, numel(testRuns));

fig = figure;
confusionchart(T.Label(isTest), Yp, 'Title', sprintf('Mechanical faults, accuracy = %.1f %%', 100*acc));
exportgraphics(fig, fullfile(repo,'results','confusion_matrix_mechanical.png'), 'Resolution',200);

%% Test 2: unseen shaft speed (train < 40 Hz, test >= 40 Hz)
isHi = T.Fr >= 40;
mdl2 = fitcensemble(T{~isHi,pn}, T.Label(~isHi), 'Method','Bag', ...
    'NumLearningCycles',50, 'Learners', tmpl);
acc2 = mean(predict(mdl2, T{isHi,pn}) == T.Label(isHi));
fprintf('Mechanical faults, unseen speed (>= 40 Hz): %.2f %%\n', 100*acc2);

%% Numeric-label model for code generation (used by the Simulink detector)
mnum = fitcensemble(T{:,pn}, double(T.Label), 'Method','Bag', ...
    'NumLearningCycles',50, 'Learners', tmpl);
saveLearnerForCoder(compact(mnum), fullfile(here,'mechModelNum'));
save(fullfile(repo,'models','mechanicalModel.mat'), 'mdl', 'T');