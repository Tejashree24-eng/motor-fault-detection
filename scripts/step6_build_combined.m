% step6_build_combined.m
% Builds MotorFaultSystem.slx: bearing detector (vibration) + electrical
% detector (current/speed) with one combined alarm.
% EDIT root to your CWRU folder.
clear; clc; bdclose all; rng(11);
root = 'C:\cwru';                        % <-- EDIT THIS
fs   = 12000;
here = fileparts(mfilename('fullpath'));
repo = fileparts(here);
addpath(here); cd(here);

%% 1) Electrical model with numeric labels (for code generation)
load(fullfile(repo,'models','electricalModel.mat'),'T');
pred = T.Properties.VariableNames(1:10);
Ye = double(T.Label);                    % 1 Healthy, 2 Open, 3 Short
me = fitcensemble(T{:,pred}, Ye, 'Method','Bag', 'NumLearningCycles',50, 'Learners', templateTree('MaxNumSplits',40));
saveLearnerForCoder(compact(me), fullfile(here,'electricalModelNum'));
rehash;
assert(isfile(fullfile(here,'electricalModelNum.mat')), 'Electrical model not created.');
assert(isfile(fullfile(here,'motorFaultModelNum.mat')), 'Run step3_build_simulink.m first (creates motorFaultModelNum.mat).');

%% 2) Demo scenario, 2 s per segment
% 0-2 s : bearing Normal,     motor Healthy
% 2-4 s : bearing Normal,     motor OpenCircuit
% 4-6 s : bearing InnerRace,  motor Healthy
% 6-8 s : bearing OuterRace,  motor ShortCircuit
segT = 2;  seg = segT*fs;
vibIds  = [100 100 108 133];
vibOff  = [0 1 0 0];
elecCls = [1 2 1 3];
alt = containers.Map({100},{'Normal_3'});

vib = [];
for s = 1:4
    n = vibIds(s);
    f = fullfile(root, sprintf('%d.mat', n));
    if ~isfile(f) && isKey(alt, n)
        f = fullfile(root, [alt(n) '.mat']);
    end
    assert(isfile(f), 'Cannot find data file for ID %d in %s', n, root);
    S  = load(f);
    fn = fieldnames(S);
    x  = S.(fn{find(endsWith(fn,'_DE_time'),1)});
    vib = [vib; x(vibOff(s)*seg+1 : (vibOff(s)+1)*seg)]; %#ok<AGROW>
end

cur = [];  spd = [];  vol = [];
for s = 1:4
    [c1, w1, V1] = simDC(elecCls(s), 1/fs, segT, 0.6);
    cur = [cur; c1];                 %#ok<AGROW>
    spd = [spd; w1];                 %#ok<AGROW>
    vol = [vol; V1*ones(size(c1))];  %#ok<AGROW>
end
t = (0:numel(vib)-1)'/fs;
assignin('base','simVib', timeseries(vib, t));
assignin('base','simCur', timeseries(cur, t));
assignin('base','simSpd', timeseries(spd, t));
assignin('base','simVol', timeseries(vol, t));

%% 3) Build the Simulink model
mdl = 'MotorFaultSystem';
new_system(mdl);
open_system(mdl);
set_param(mdl,'SolverType','Fixed-step','Solver','FixedStepDiscrete','FixedStep','1/12000','StopTime',num2str(t(end)));

add_block('simulink/Sources/From Workspace',[mdl '/Vibration'],'VariableName','simVib','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/Current'],'VariableName','simCur','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/Speed'],'VariableName','simSpd','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/Voltage'],'VariableName','simVol','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');

add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/BearingDetector']);
add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/ElectricalDetector']);
add_block('simulink/Logic and Bit Operations/Logical Operator',[mdl '/SystemAlarm'],'Operator','OR','Inputs','2');
add_block('simulink/Sinks/Display',[mdl '/BearingClass']);
add_block('simulink/Sinks/Display',[mdl '/ElectricalClass']);
add_block('simulink/Sinks/Display',[mdl '/AlarmDisplay']);
add_block('simulink/Sinks/Scope',[mdl '/Scope'],'NumInputPorts','4');

ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/BearingDetector']);
ch.Script = sprintf('function [label, alarm] = BearingDetector(u)\n[label, alarm] = motorDetector(u);\n');
ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/ElectricalDetector']);
ch.Script = sprintf('function [label, alarm] = ElectricalDetector(c, s, v)\n[label, alarm] = electricalDetector(c, s, v);\n');

add_line(mdl,'Vibration/1','BearingDetector/1');
add_line(mdl,'Current/1','ElectricalDetector/1');
add_line(mdl,'Speed/1','ElectricalDetector/2');
add_line(mdl,'Voltage/1','ElectricalDetector/3');
add_line(mdl,'BearingDetector/2','SystemAlarm/1');
add_line(mdl,'ElectricalDetector/2','SystemAlarm/2');
add_line(mdl,'Vibration/1','Scope/1');
add_line(mdl,'BearingDetector/1','Scope/2');
add_line(mdl,'ElectricalDetector/1','Scope/3');
add_line(mdl,'SystemAlarm/1','Scope/4');
add_line(mdl,'BearingDetector/1','BearingClass/1');
add_line(mdl,'ElectricalDetector/1','ElectricalClass/1');
add_line(mdl,'SystemAlarm/1','AlarmDisplay/1');
Simulink.BlockDiagram.arrangeSystem(mdl);

simDir = fullfile(repo,'simulink');
if ~exist(simDir,'dir'), mkdir(simDir); end
save_system(mdl, fullfile(simDir, mdl));

%% 4) Run
sim(mdl);
open_system([mdl '/Scope']);
disp('Done. Screenshot the Scope and save it as results/simulink_scope_combined.png');

%% ---- local function: DC motor simulation (same equations as step 5)
function [cur, spd, Va] = simDC(c, dt, Tseg, Tskip)
tol = @() 1 + 0.08*(2*rand - 1);
n  = round((Tseg+Tskip)/dt);
Ra = 2.0*tol();  La = 2e-3*tol();  Ke = 0.1*tol();
J  = 5e-4*tol(); B  = 1e-4*tol();
Va = 18 + 12*rand;
TL = 0.05 + 0.20*rand;
k = 0;
if c == 3, k = 0.10 + 0.20*rand; end
Ra = Ra*(1-k);  La = La*(1-k)^2;  Ke = Ke*(1-k);
Tp = 0.08 + 0.07*rand;  Td = 0.01 + 0.02*rand;  ph = rand*Tp;
i = zeros(n,1);  w = zeros(n,1);
for s = 2:n
    t = (s-1)*dt;
    if c == 2 && mod(t+ph, Tp) < Td
        i(s) = 0;
    else
        i(s) = i(s-1) + dt*(Va - Ra*i(s-1) - Ke*w(s-1))/La;
    end
    w(s) = max(0, w(s-1) + dt*(Ke*i(s-1) - B*w(s-1) - TL)/J);
end
i = i + 0.02*randn(n,1);
w = w + 0.5*randn(n,1);
sk  = round(Tskip/dt);
cur = i(sk+1:end);
spd = w(sk+1:end);
end