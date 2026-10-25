function [label, alarm] = mechanicalDetector(x, fr) %#codegen
% label: 1=Normal 2=Unbalance 3=Misalignment
% alarm: 1 when 3 consecutive windows are faulty
persistent buf idx mdl lastLabel cnt
fs = 12000;  N = 4096;
if isempty(buf)
    buf = zeros(N,1);  idx = 0;
    mdl = loadLearnerForCoder('mechModelNum');
    lastLabel = 1;  cnt = 0;
end
idx = idx + 1;
buf(idx) = x;
if idx == N
    idx = 0;
    f = mechFeatures(buf, fs, fr);
    lastLabel = double(predict(mdl, f));
    if lastLabel ~= 1
        cnt = cnt + 1;
    else
        cnt = 0;
    end
end
label = lastLabel;
alarm = double(cnt >= 3);
end