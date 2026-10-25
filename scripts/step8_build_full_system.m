% step8_build_full_system.m
% Builds MotorFaultSystem.slx with three detectors and one combined alarm:
%   1) bearing (CWRU vibration)  2) electrical (current/speed)  3) mechanical (unbalance/misalignment)
% EDIT root to your CWRU folder.
clear; clc; bdclose all; rng(21);
root = 'C:\cwru';                        % <-- EDIT THIS
fs   = 12000;
here = fileparts(mfilename('fullpath'));
repo = fileparts(here);
addpath(here); cd(here);

assert(isfile(fullfile(here,'motorFaultModelNum.mat')), 'Missing motorFaultModelNum.mat (run step3_build_simulink.m).');
assert(isfile(fullfile(here,'electricalModelNum.mat')), 'Missing electricalModelNum.mat (run step6_build_combined.m).');
assert(isfile(fullfile(here,'mechModelNum.mat')), 'Missing mechModelNum.mat (run step7_mechanical_faults.m).');

%% Demo scenario, 2 s per segment
% 0-2 s : all healthy
% 2-4 s : electrical OpenCircuit
% 4-6 s : bearing InnerRace, mechanical Unbalance
% 6-8 s : bearing OuterRace, electrical ShortCircuit, mechanical Misalignment
segT = 2;  seg = segT*fs;
vibIds  = [100 100 108 133];
vibOff  = [0 1 0 0];
elecCls = [1 2 1 3];
mechCls = [1 1 2 3];
mechFr  = [30 35 45 25];
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

cur = [];  spd = [];  vol = [];  mx = [];  frv = [];
for s = 1:4
    [c1, w1, V1] = simDC(elecCls(s), 1/fs, segT, 0.6);
    cur = [cur; c1];                 %#ok<AGROW>
    spd = [spd; w1];                 %#ok<AGROW>
    vol = [vol; V1*ones(size(c1))];  %#ok<AGROW>
    m1  = simMech(mechCls(s), fs, segT, mechFr(s));
    mx  = [mx; m1];                  %#ok<AGROW>
    frv = [frv; mechFr(s)*ones(size(m1))]; %#ok<AGROW>
end
t = (0:numel(vib)-1)'/fs;
assignin('base','simVib', timeseries(vib, t));
assignin('base','simCur', timeseries(cur, t));
assignin('base','simSpd', timeseries(spd, t));
assignin('base','simVol', timeseries(vol, t));
assignin('base','simMech', timeseries(mx, t));
assignin('base','simFr', timeseries(frv, t));

%% Build the Simulink model
mdl = 'MotorFaultSystem';
new_system(mdl);
open_system(mdl);
set_param(mdl,'SolverType','Fixed-step','Solver','FixedStepDiscrete','FixedStep','1/12000','StopTime',num2str(t(end)));

add_block('simulink/Sources/From Workspace',[mdl '/Vibration'],'VariableName','simVib','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/Current'],'VariableName','simCur','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/Speed'],'VariableName','simSpd','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/Voltage'],'VariableName','simVol','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/MechAccel'],'VariableName','simMech','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');
add_block('simulink/Sources/From Workspace',[mdl '/ShaftFreq'],'VariableName','simFr','SampleTime','1/12000','OutputAfterFinalValue','Holding final value');

add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/BearingDetector']);
add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/ElectricalDetector']);
add_block('simulink/User-Defined Functions/MATLAB Function',[mdl '/MechDetector']);
add_block('simulink/Logic and Bit Operations/Logical Operator',[mdl '/SystemAlarm'],'Operator','OR','Inputs','3');
add_block('simulink/Sinks/Display',[mdl '/BearingClass']);
add_block('simulink/Sinks/Display',[mdl '/ElectricalClass']);
add_block('simulink/Sinks/Display',[mdl '/MechClass']);
add_block('simulink/Sinks/Display',[mdl '/AlarmDisplay']);
add_block('simulink/Sinks/Scope',[mdl '/Scope'],'NumInputPorts','5');

ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/BearingDetector']);
ch.Script = sprintf('function [label, alarm] = BearingDetector(u)\n[label, alarm] = motorDetector(u);\n');
ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/ElectricalDetector']);
ch.Script = sprintf('function [label, alarm] = ElectricalDetector(c, s, v)\n[label, alarm] = electricalDetector(c, s, v);\n');
ch = sfroot().find('-isa','Stateflow.EMChart','Path',[mdl '/MechDetector']);
ch.Script = sprintf('function [label, alarm] = MechDetector(x, fr)\n[label, alarm] = mechanicalDetector(x, fr);\n');

add_line(mdl,'Vibration/1','BearingDetector/1');
add_line(mdl,'Current/1','ElectricalDetector/1');
add_line(mdl,'Speed/1','ElectricalDetector/2');
add_line(mdl,'Voltage/1','ElectricalDetector/3');
add_line(mdl,'MechAccel/1','MechDetector/1');
add_line(mdl,'ShaftFreq/1','MechDetector/2');
add_line(mdl,'BearingDetector/2','SystemAlarm/1');
add_line(mdl,'ElectricalDetector/2','SystemAlarm/2');
add_line(mdl,'MechDetector/2','SystemAlarm/3');
add_line(mdl,'Vibration/1','Scope/1');
add_line(mdl,'BearingDetector/1','Scope/2');
add_line(mdl,'ElectricalDetector/1','Scope/3');
add_line(mdl,'MechDetector/1','Scope/4');
add_line(mdl,'SystemAlarm/1','Scope/5');
add_line(mdl,'BearingDetector/1','BearingClass/1');
add_line(mdl,'ElectricalDetector/1','ElectricalClass/1');
add_line(mdl,'MechDetector/1','MechClass/1');
add_line(mdl,'SystemAlarm/1','AlarmDisplay/1');
Simulink.BlockDiagram.arrangeSystem(mdl);

simDir = fullfile(repo,'simulink');
if ~exist(simDir,'dir'), mkdir(simDir); end
save_system(mdl, fullfile(simDir, mdl));

sim(mdl);
open_system([mdl '/Scope']);
disp('Done. Screenshot the Scope and save it as results/simulink_scope_full.png');

%% ---- local functions
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

function x = simMech(c, fs, Tseg, fr)
n  = round(Tseg*fs);
tt = (0:n-1)'/fs;
sev = 0.5 + rand;  gain = 0.8 + 0.4*rand;  sig = 0.03 + 0.03*rand;
if c == 1
    a = [0.03 0.015 0.005];
elseif c == 2
    a = [0.5*sev*(fr/35)^2, 0.03, 0.01];
else
    a = [0.10*sev, 0.45*sev, 0.12*sev];
end
a = a*gain;
x = zeros(n,1);
for k = 1:3
    x = x + a(k)*sin(2*pi*k*fr*tt + 2*pi*rand);
end
x = x + sig*randn(n,1) + 0.5*sig*filter(1,[1 -1.2 0.6],randn(n,1));
end