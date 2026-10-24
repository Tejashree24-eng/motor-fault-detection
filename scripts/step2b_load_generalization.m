% step2b_load_generalization.m
% Harder test: train on motor loads 0-2 HP, test on unseen load 3 HP.
clear; clc; rng(1);
here = fileparts(mfilename('fullpath'));
load(fullfile(here,'..','models','featureTable.mat'),'T');
predNames = T.Properties.VariableNames(1:10);

loadIdx = mod(T.FileID-1, 4);      % 0,1,2,3 HP (files were added in load order)
isTest  = (loadIdx == 3);

tmpl = templateTree('MaxNumSplits', 40);
mdl  = fitcensemble(T{~isTest,predNames}, T.Label(~isTest), ...
    'Method','Bag','NumLearningCycles',50,'Learners',tmpl);
Ypred = predict(mdl, T{isTest,predNames});
acc = mean(Ypred == T.Label(isTest));
fprintf('Unseen-load (3 HP) accuracy: %.2f %%\n', 100*acc);

fig = figure;
confusionchart(T.Label(isTest), Ypred, 'Title', ...
    sprintf('Unseen load test, accuracy = %.1f %%', 100*acc));
exportgraphics(fig, fullfile(here,'..','results','confusion_matrix_unseen_load.png'),'Resolution',200);