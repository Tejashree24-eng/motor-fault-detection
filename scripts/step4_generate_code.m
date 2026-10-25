% step4_generate_code.m
% Builds MotorFaultDeploy.slx and generates C code for an ARM Cortex-M target
% (the architecture of the STM32H743 on the NUCLEO-H743ZI2).
clear; clc; bdclose all;
here = fileparts(mfilename('fullpath'));
repo = fileparts(here);
addpath(here); cd(here);

mdl = 'MotorFaultDeploy';
new_system(mdl); open_system(mdl);
set_param(mdl,'SolverType','Fixed-step','Solver','FixedStepDiscrete', ...
    'FixedStep','1/12000');

add_block('simulink/Sources/In1', [mdl '/accel'], 'SampleTime','1/12000');
add_block('simulink/User-Defined Functions/MATLAB Function', [mdl '/Detector']);
add_block('simulink/Sinks/Out1', [mdl '/faultClass']);
add_block('simulink/Sinks/Out1', [mdl '/alarm']);

chart = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/Detector']);
chart.Script = sprintf(['function [label, alarm] = Detector(u)\n' ...
    '[label, alarm] = motorDetector(u);\n']);

add_line(mdl,'accel/1','Detector/1');
add_line(mdl,'Detector/1','faultClass/1');
add_line(mdl,'Detector/2','alarm/1');
Simulink.BlockDiagram.arrangeSystem(mdl);

% ---- Target: ARM Cortex-M (code generation only)
set_param(mdl,'SystemTargetFile','grt.tlc');   % use 'grt.tlc' if no Embedded Coder
set_param(mdl,'ProdHWDeviceType','ARM Compatible->ARM Cortex-M');
set_param(mdl,'GenCodeOnly','on');
set_param(mdl,'GenerateReport','on');

simDir = fullfile(repo,'simulink');
if ~exist(simDir,'dir'), mkdir(simDir); end
save_system(mdl, fullfile(simDir, mdl));

slbuild(mdl);
disp('Code generated. Take a screenshot of the code generation report.');
