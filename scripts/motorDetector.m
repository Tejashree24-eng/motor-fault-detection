function [label, alarm] = motorDetector(x) %#codegen
% label: 1=Normal 2=InnerRace 3=Ball 4=OuterRace
% alarm: 1 when 3 consecutive windows are faulty
persistent buf idx mdl lastLabel cnt
fs = 12000;  N = 2048;
if isempty(buf)
    buf = zeros(N,1);  idx = 0;
    mdl = loadLearnerForCoder('motorFaultModelNum');
    lastLabel = 1;  cnt = 0;
end
idx = idx + 1;
buf(idx) = x;
if idx == N
    idx = 0;
    f = [mean(buf), std(buf), rms(buf), max(abs(buf)), kurtosis(buf), ...
        skewness(buf), max(abs(buf))/rms(buf), ...
        bandpower(buf,fs,[1 1000]), ...
        bandpower(buf,fs,[1000 3000]), ...
        bandpower(buf,fs,[3000 5500])];
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