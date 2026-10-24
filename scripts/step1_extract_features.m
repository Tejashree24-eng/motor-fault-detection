% 01_extract_features.m
% CWRU bearing dataset -> feature table (drive-end accelerometer)
% EDIT 'root' below to the folder that contains your .mat files.

clear; clc;
root   = 'C:\cwru';     % <-- EDIT THIS
fs     = 12000;         % CWRU sampling rate (Hz)
winLen = 2048;          % samples per window (~0.17 s)

classes = ["Normal","InnerRace","Ball","OuterRace"];
ids = { 97:100, ...
    [105:108 169:172], ...
    [118:121 185:188], ...
    [130:133 197:200] };

% Optional alternative names for the Normal files
altNames = containers.Map({97,98,99,100}, ...
    {'Normal_0','Normal_1','Normal_2','Normal_3'});

rows = {};
fileID = 0;
for c = 1:numel(classes)
    for n = ids{c}
        fname = fullfile(root, sprintf('%d.mat', n));
        if ~isfile(fname) && isKey(altNames, n)
            fname = fullfile(root, [altNames(n) '.mat']);
        end
        if ~isfile(fname)
            warning('Missing file for ID %d, skipping.', n);
            continue
        end

        S  = load(fname);
        fn = fieldnames(S);
        k  = find(endsWith(fn, '_DE_time'), 1);
        if isempty(k)
            warning('No DE signal in %s, skipping.', fname);
            continue
        end
        x_all = S.(fn{k});
        x_all = x_all(:);

        fileID = fileID + 1;
        nWin = floor(numel(x_all) / winLen);
        for w = 1:nWin
            x = x_all((w-1)*winLen+1 : w*winLen);
            f = [mean(x), std(x), rms(x), max(abs(x)), kurtosis(x), ...
                skewness(x), max(abs(x))/rms(x), ...
                bandpower(x, fs, [1 1000]), ...
                bandpower(x, fs, [1000 3000]), ...
                bandpower(x, fs, [3000 5500])];
            rows{end+1,1} = [f, fileID, c]; %#ok<SAGROW>
        end
    end
end

M = vertcat(rows{:});
names = ["mean","std","rms","peak","kurt","skew","crest", ...
    "bp0_1k","bp1k_3k","bp3k_5k"];
T = array2table(M(:,1:10), 'VariableNames', cellstr(names));
T.FileID = M(:,11);
T.Label  = categorical(M(:,12), 1:4, cellstr(classes));

% Save into <repo>/models regardless of current folder
here   = fileparts(mfilename('fullpath'));
outDir = fullfile(here, '..', 'models');
if ~exist(outDir, 'dir'), mkdir(outDir); end
save(fullfile(outDir, 'featureTable.mat'), 'T');

fprintf('Files used: %d\n', fileID);
disp(groupsummary(T, 'Label'))