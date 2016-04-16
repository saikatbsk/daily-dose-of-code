% Cleanup workspace and command window ====================================

clear; clc;

% Defining path and loading dataset =======================================

datasetFolderRoot = fullfile('~/Workspace/Datasets/101_ObjectCategories');
imageSets = [imageSet(fullfile(datasetFolderRoot, 'dolphin')), ...
    imageSet(fullfile(datasetFolderRoot, 'airplanes')), ...
    imageSet(fullfile(datasetFolderRoot, 'bonsai')), ...
    imageSet(fullfile(datasetFolderRoot, 'cellphone'))];

% Preparing training and validation image sets ============================
% We want equal number of images in all training sets.  We can take the min
% of all the training sets and use that number to trim our dataset.
% =========================================================================

minSetCount = min([imageSets.Count]);
imageSets   = partition(imageSets, minSetCount, 'randomize');

% Separate set into training and validation data ==========================

[trainingSets, validationSets] = partition(imageSets, 0.8, 'randomize');

% Creating visual vocabulary and training an image category classifier ====
% 1. Extract SURF features from all images in all image categories.
% 2. Construct a visual vocabulary using K-means clustering.
% =========================================================================


