% step9_tidy_diagram.m
% Re-lays out MotorFaultDeploy.slx in clean columns: inputs | detectors | alarm | outputs
clear; clc; bdclose all;
here = fileparts(mfilename('fullpath'));
repo = fileparts(here);
mdl  = 'MotorFaultDeploy';
load_system(fullfile(repo,'simulink',mdl));
open_system(mdl);

% ---- Detector blocks (wide, so the names don't overlap the port labels)
set_param([mdl '/BearingDetector'],   'Position',[300  40 520 150]);
set_param([mdl '/ElectricalDetector'],'Position',[300 230 520 370]);
set_param([mdl '/MechDetector'],      'Position',[300 450 520 560]);
set_param([mdl '/SystemAlarm'],       'Position',[700 280 750 360]);

set_param([mdl '/BearingDetector'],   'BackgroundColor','lightBlue');
set_param([mdl '/ElectricalDetector'],'BackgroundColor','yellow');
set_param([mdl '/MechDetector'],      'BackgroundColor','green');
set_param([mdl '/SystemAlarm'],       'BackgroundColor','orange');

% ---- Put every inport / outport at the height of the port it connects to
pb = get_param([mdl '/BearingDetector'],   'PortHandles');
pe = get_param([mdl '/ElectricalDetector'],'PortHandles');
pm = get_param([mdl '/MechDetector'],      'PortHandles');
pa = get_param([mdl '/SystemAlarm'],       'PortHandles');

place([mdl '/accel'],      pb.Inport(1),  100);
place([mdl '/current'],    pe.Inport(1),  100);
place([mdl '/speed'],      pe.Inport(2),  100);
place([mdl '/voltage'],    pe.Inport(3),  100);
place([mdl '/mechAccel'],  pm.Inport(1),  100);
place([mdl '/shaftFreq'],  pm.Inport(2),  100);

place([mdl '/bearingClass'],    pb.Outport(1), 880);
place([mdl '/electricalClass'], pe.Outport(1), 880);
place([mdl '/mechClass'],       pm.Outport(1), 880);
place([mdl '/alarm'],           pa.Outport(1), 880);

set_param(mdl,'ZoomFactor','FitSystem');
save_system(mdl);

% ---- Save a picture for the report
resDir = fullfile(repo,'results');
if ~exist(resDir,'dir'), mkdir(resDir); end
print(['-s' mdl], '-dpng', '-r200', fullfile(resDir,'simulink_model_deploy.png'));
disp('Done. Saved results/simulink_model_deploy.png');

function place(blk, portHandle, xLeft)
p = get_param(portHandle,'Position');
y = p(2);
set_param(blk,'Position',[xLeft y-7 xLeft+30 y+7]);
end