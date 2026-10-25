% step4_generate_code.m
% Builds MotorFaultDeploy.slx with all three detectors (bearing, electrical,
% mechanical), lays it out cleanly, and generates C code (grt.tlc) for an
% ARM Cortex-M device type.
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

% ---- Tidy layout: inputs | detectors | alarm | outputs
set_param([mdl '/BearingDetector'],   'Position',[300  40 520 150]);
set_param([mdl '/ElectricalDetector'],'Position',[300 230 520 370]);
set_param([mdl '/MechDetector'],      'Position',[300 450 520 560]);
set_param([mdl '/SystemAlarm'],       'Position',[700 280 750 360]);
set_param([mdl '/BearingDetector'],   'BackgroundColor','lightBlue');
set_param([mdl '/ElectricalDetector'],'BackgroundColor','yellow');
set_param([mdl '/MechDetector'],      'BackgroundColor','green');
set_param([mdl '/SystemAlarm'],       'BackgroundColor','orange');

pb = get_param([mdl '/BearingDetector'],   'PortHandles');
pe = get_param([mdl '/ElectricalDetector'],'PortHandles');
pm = get_param([mdl '/MechDetector'],      'PortHandles');
pa = get_param([mdl '/SystemAlarm'],       'PortHandles');
placeBlock([mdl '/accel'],      pb.Inport(1),  100);
placeBlock([mdl '/current'],    pe.Inport(1),  100);
placeBlock([mdl '/speed'],      pe.Inport(2),  100);
placeBlock([mdl '/voltage'],    pe.Inport(3),  100);
placeBlock([mdl '/mechAccel'],  pm.Inport(1),  100);
placeBlock([mdl '/shaftFreq'],  pm.Inport(2),  100);
placeBlock([mdl '/bearingClass'],    pb.Outport(1), 880);
placeBlock([mdl '/electricalClass'], pe.Outport(1), 880);
placeBlock([mdl '/mechClass'],       pm.Outport(1), 880);
placeBlock([mdl '/alarm'],           pa.Outport(1), 880);
set_param(mdl,'ZoomFactor','FitSystem');

% ---- Target: generic real-time target, ARM Cortex-M device type, code only
set_param(mdl,'SystemTargetFile','grt.tlc');
set_param(mdl,'ProdHWDeviceType','ARM Compatible->ARM Cortex-M');
set_param(mdl,'GenCodeOnly','on');
set_param(mdl,'GenerateReport','on');

simDir = fullfile(repo,'simulink');
if ~exist(simDir,'dir'), mkdir(simDir); end
save_system(mdl, fullfile(simDir, mdl));

% ---- Save a picture of the tidy model for the report
resDir = fullfile(repo,'results');
if ~exist(resDir,'dir'), mkdir(resDir); end
print(['-s' mdl], '-dpng', '-r200', fullfile(resDir,'simulink_model_deploy.png'));

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

function placeBlock(blk, portHandle, xLeft)
    p = get_param(portHandle,'Position');
    y = p(2);
    set_param(blk,'Position',[xLeft y-7 xLeft+30 y+7]);
end