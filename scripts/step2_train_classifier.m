% step2_train_classifier.m
% Train a bagged-tree classifier on CWRU features, test on unseen files.

clear; clc; rng(1);
here = fileparts(mfilename('fullpath'));
load(fullfile(here,'..','models','featureTable.mat'),'T');

predNames = T.Properties.VariableNames(1:10);   % the 10 features

% ---- Split by FILE (about 25% of files per class go to the test set)
[fileIDs, ia] = unique(T.FileID);
fileLabel = T.Label(ia);
cats = categories(T.Label);
testFiles = [];
for i = 1:numel(cats)
    f = fileIDs(fileLabel == cats{i});
    nTest = max(1, round(0.25*numel(f)));
    testFiles = [testFiles; f(randperm(numel(f), nTest))]; %#ok<AGROW>
end
isTest = ismember(T.FileID, testFiles);

Xtr = T{~isTest, predNames};   Ytr = T.Label(~isTest);
Xte = T{ isTest, predNames};   Yte = T.Label( isTest);
fprintf('Train windows: %d | Test windows: %d | Test files: %d\n', ...
    numel(Ytr), numel(Yte), numel(testFiles));

% ---- Train
tmpl = templateTree('MaxNumSplits', 40);
mdl  = fitcensemble(Xtr, Ytr, 'Method','Bag', ...
    'NumLearningCycles', 50, 'Learners', tmpl);

% ---- Test
Ypred = predict(mdl, Xte);
acc = mean(Ypred == Yte);
fprintf('Test accuracy: %.2f %%\n', 100*acc);

% ---- Confusion matrix
fig = figure;
confusionchart(Yte, Ypred, 'Title', ...
    sprintf('Test accuracy = %.1f %%', 100*acc));
resDir = fullfile(here,'..','results');
if ~exist(resDir,'dir'), mkdir(resDir); end
exportgraphics(fig, fullfile(resDir,'confusion_matrix.png'), 'Resolution',200);

% ---- Save model (normal + code-generation version)
cmdl = compact(mdl);
save(fullfile(here,'..','models','trainedModel.mat'), 'cmdl', 'predNames');
saveLearnerForCoder(cmdl, fullfile(here,'..','models','motorFaultModel'));