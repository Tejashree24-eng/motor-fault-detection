% step4_generate_code.m
% Builds MotorFaultDeploy.slx with all three detectors (bearing, electrical,
% mechanical) and generates C code (grt.tlc) for an ARM Cortex-M device type.
clear; clc; bdclose all;
here = fileparts(mfilename('fullpath'));
repo = fileparts(here);
addpath(here); cd(here);

assert(isfile(fullfile(here,'motorFaultModelNum.mat')), 'Missing motorFaultModelNum.mat (run step3_build_simulink.m).');
assert(isfile(fullfile(here,'electricalModelNum.mat')), 'Missing electricalModelNum.mat (run step6_build_combined.m).');
assert(isfile(fullfile(here,'mechModelNum.mat')), 'Missing mechModelNum.mat (run step7_mechanical_faults.m).');

mdl = 'MotorFaultDeploy';
new_system(mdl);
open_system(mdl);
set_param(mdl,'SolverType','Fixed-step','Solver','FixedStepDiscrete','FixedStep','1/12000');

% ---- Inputs
add_block('simulink/Sources/In1',[mdl '/accel'],'SampleTime','1/12000');
add_block('simulink/Sources/In1',[mdl '/current'],'SampleTime','1/12000');
add_block('simulink/Sources/In1',[mdl '/speed'],'SampleTime','1/12000');
add_block('simulink/Sources/In1',[mdl '/voltage'],'SampleTime','1/12000');
add_block('simulink/Sources/In1',[mdl '/mechAccel'],'SampleTime','1/12000');
add_block('simulink/Sources/In1',[mdl '/shaftFreq'],'SampleTime','1/12000');

% ---- Detectors
add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/BearingDetector']);
add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/ElectricalDetector']);
add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/MechDetector']);
add_block('simulink/Logic and Bit Operations/Logical Operator',[mdl '/SystemAlarm'],'Operator','OR','Inputs','3');

% ---- Outputs
add_block('simulink/Sinks/Out1',[mdl '/bearingClass']);
add_block('simulink/Sinks/Out1',[mdl '/electricalClass']);
add_block('simulink/Sinks/Out1',[mdl '/mechClass']);
add_block('simulink/Sinks/Out1',[mdl '/alarm']);

ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/BearingDetector']);
ch.Script = sprintf('function [label, alarm] = BearingDetector(u)\n[label, alarm] = motorDetector(u);\n');
ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/ElectricalDetector']);
ch.Script = sprintf('function [label, alarm] = ElectricalDetector(c, s, v)\n[label, alarm] = electricalDetector(c, s, v);\n');
ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/MechDetector']);
ch.Script = sprintf('function [label, alarm] = MechDetector(x, fr)\n[label, alarm] = mechanicalDetector(x, fr);\n');

add_line(mdl,'accel/1','BearingDetector/1');
add_line(mdl,'current/1','ElectricalDetector/1');
add_line(mdl,'speed/1','ElectricalDetector/2');
add_line(mdl,'voltage/1','ElectricalDetector/3');
add_line(mdl,'mechAccel/1','MechDetector/1');
add_line(mdl,'shaftFreq/1','MechDetector/2');
add_line(mdl,'BearingDetector/2','SystemAlarm/1');
add_line(mdl,'ElectricalDetector/2','SystemAlarm/2');
add_line(mdl,'MechDetector/2','SystemAlarm/3');
add_line(mdl,'BearingDetector/1','bearingClass/1');
add_line(mdl,'ElectricalDetector/1','electricalClass/1');
add_line(mdl,'MechDetector/1','mechClass/1');
add_line(mdl,'SystemAlarm/1','alarm/1');
Simulink.BlockDiagram.arrangeSystem(mdl);

% ---- Target: generic real-time target, ARM Cortex-M device type, code only
set_param(mdl,'SystemTargetFile','grt.tlc');
set_param(mdl,'ProdHWDeviceType','ARM Compatible->ARM Cortex-M');
set_param(mdl,'GenCodeOnly','on');
set_param(mdl,'GenerateReport','on');

simDir = fullfile(repo,'simulink');
if ~exist(simDir,'dir'), mkdir(simDir); end
save_system(mdl, fullfile(simDir, mdl));

% ---- Build, with the full error message if it fails
try
    slbuild(mdl);
    disp('Code generated for all three detectors. Screenshot the code generation report.');
catch ME
    disp(getReport(ME,'extended'));
    for k = 1:numel(ME.cause)
        disp(ME.cause{k}.message);
    end
end