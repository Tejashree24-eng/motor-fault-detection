function [label, alarm] = electricalDetector(cur, spd, volt) %#codegen
% label: 1=Healthy 2=OpenCircuit 3=ShortCircuit
% alarm: 1 when 3 consecutive windows are faulty
persistent bc bs idx mdl lastLabel cnt
N = 2400;
if isempty(bc)
    bc = zeros(N,1);  bs = zeros(N,1);  idx = 0;
    mdl = loadLearnerForCoder('electricalModelNum');
    lastLabel = 1;  cnt = 0;
end
idx = idx + 1;
bc(idx) = cur;  bs(idx) = spd;
if idx == N
    idx = 0;
    f = [mean(bc), std(bc), rms(bc), max(abs(bc)), kurtosis(bc), ...
        skewness(bc), max(abs(bc))/rms(bc), ...
        mean(bs), std(bs), mean(bs)/volt];
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