% step3_build_simulink.m
% Trains the code-generation model, builds MotorFaultDetector.slx and runs a demo.
% EDIT 'root' below to your CWRU folder.

clear; clc; bdclose all;
root = 'C:\cwru';                        % <-- EDIT THIS
fs   = 12000;

here = fileparts(mfilename('fullpath')); % .../scripts
repo = fileparts(here);                  % repo root
addpath(here);
cd(here);

%% 1) Train numeric-label model for code generation
load(fullfile(repo,'models','featureTable.mat'),'T');
pred = T.Properties.VariableNames(1:10);
Y = double(T.Label);                     % 1 Normal, 2 Inner, 3 Ball, 4 Outer
m = fitcensemble(T{:,pred}, Y, 'Method','Bag', 'NumLearningCycles',50, ...
    'Learners', templateTree('MaxNumSplits',40));
saveLearnerForCoder(compact(m), fullfile(here,'motorFaultModelNum'));
rehash;
assert(isfile(fullfile(here,'motorFaultModelNum.mat')), ...
    'Model file was not created.');

%% 2) Demo signal: Normal -> InnerRace -> Ball -> OuterRace (2 s each)
ids = [100 108 121 133];                 % 3 HP files
alt = containers.Map({97,98,99,100}, ...
    {'Normal_0','Normal_1','Normal_2','Normal_3'});
seg = 2*fs;
sig = [];
for n = ids
    f = fullfile(root, sprintf('%d.mat', n));
    if ~isfile(f) && isKey(alt, n)
        f = fullfile(root, [alt(n) '.mat']);
    end
    assert(isfile(f), 'Cannot find data file for ID %d in %s', n, root);
    S  = load(f);
    fn = fieldnames(S);
    x  = S.(fn{find(endsWith(fn,'_DE_time'),1)});
    sig = [sig; x(1:seg)]; %#ok<AGROW>
end
t = (0:numel(sig)-1)'/fs;
simIn = timeseries(sig, t);
assignin('base','simIn',simIn);

%% 3) Build the Simulink model
mdl = 'MotorFaultDetector';
new_system(mdl);
open_system(mdl);
set_param(mdl, 'SolverType','Fixed-step', 'Solver','FixedStepDiscrete', ...
    'FixedStep','1/12000', 'StopTime', num2str(t(end)));

add_block('simulink/Sources/From Workspace', [mdl '/Sensor'], ...
    'VariableName','simIn', 'SampleTime','1/12000', ...
    'OutputAfterFinalValue','Holding final value');
add_block('simulink/User-Defined Functions/MATLAB Function', [mdl '/Detector']);
add_block('simulink/Sinks/Display', [mdl '/ClassDisplay']);
add_block('simulink/Sinks/Display', [mdl '/AlarmDisplay']);
add_block('simulink/Sinks/Scope',   [mdl '/Scope'], 'NumInputPorts','3');

chart = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/Detector']);
chart.Script = sprintf(['function [label, alarm] = Detector(u)\n' ...
    '[label, alarm] = motorDetector(u);\n']);

add_line(mdl, 'Sensor/1',   'Detector/1');
add_line(mdl, 'Sensor/1',   'Scope/1');
add_line(mdl, 'Detector/1', 'Scope/2');
add_line(mdl, 'Detector/2', 'Scope/3');
add_line(mdl, 'Detector/1', 'ClassDisplay/1');
add_line(mdl, 'Detector/2', 'AlarmDisplay/1');
Simulink.BlockDiagram.arrangeSystem(mdl);

simDir = fullfile(repo,'simulink');
if ~exist(simDir,'dir'), mkdir(simDir); end
save_system(mdl, fullfile(simDir, mdl));

%% 4) Run the simulation
sim(mdl);
open_system([mdl '/Scope']);
disp('Done. Take a screenshot of the Scope and save it as results/simulink_scope.png');