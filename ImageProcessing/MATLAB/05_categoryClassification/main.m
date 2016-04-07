% Cleanup workspace and command window ====================================

clear; clc;

% Defining path and loading dataset =======================================

datasetFolderRoot = fullfile('~/Workspace/Datasets/101_ObjectCategories');
imageSets = [imageSet(fullfile(datasetFolderRoot, 'accordion')), ...
    imageSet(fullfile(datasetFolderRoot, 'airplanes')), ...
    imageSet(fullfile(datasetFolderRoot, 'butterfly')), ...
    imageSet(fullfile(datasetFolderRoot, 'camera')), ...
    imageSet(fullfile(datasetFolderRoot, 'chair')), ...
    imageSet(fullfile(datasetFolderRoot, 'cup')), ...
    imageSet(fullfile(datasetFolderRoot, 'lamp')), ...
    imageSet(fullfile(datasetFolderRoot, 'laptop')), ...
    imageSet(fullfile(datasetFolderRoot, 'saxophone')), ...
    imageSet(fullfile(datasetFolderRoot, 'umbrella'))];

% Preparing training and validation image sets ============================
% We want equal number of images in all training sets.  We can take the min
% of all the training sets and use that number to trim our dataset.
% =========================================================================

minSetCount = min([imageSets.Count]);
imageSets = partition(imageSets, minSetCount, 'randomize');

% Separate set into training and validation data ==========================

[trainingSets, validationSets] = partition(imageSets, 0.4, 'randomize');

% Detect and show interest points =========================================

img = read(imageSets(1), 1);
img = rgb2gray(img);
SURFPoints = detectSURFFeatures(img);

imshow(img);
hold on;
plot(SURFPoints.selectStrongest(30));

pause;

% Creating visual vocabulary and training an image category classifier ====
% 1. Extract SURF features from all images in all image categories.
% 2. Construct  a  visual vocabulary  by reducing  the number  of  features
%    through quantization of feature using K-means clustering.
% =========================================================================

bag = bagOfFeatures(trainingSets);

% The "Visual Word Occurrences" histogram =================================

img = read(imageSets(1), 1);
featureVector = encode(bag, img);

figure
bar(featureVector)
title('Visual Word Occurrences')
xlabel('Visual word index')
ylabel('Frequency of occurrence')

pause;

% Train the classifier ====================================================

categoryClassifier = trainImageCategoryClassifier(trainingSets, bag);
