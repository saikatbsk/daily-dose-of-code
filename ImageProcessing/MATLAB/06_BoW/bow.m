% Cleanup workspace and command window ====================================

clear; clc;

% Defining path and loading dataset =======================================

datasetFolderRoot = fullfile('~/Workspace/Datasets/texture');
imageSets = [imageSet(fullfile(datasetFolderRoot, '1')), ...
    imageSet(fullfile(datasetFolderRoot, '2')), ...
    imageSet(fullfile(datasetFolderRoot, '3'))];

% Preparing training and validation image sets ============================
% We want equal number of images in all training sets.  We can take the min
% of all the training sets and use that number to trim our dataset.
% =========================================================================

minSetCount = min([imageSets.Count]);
imageSets   = partition(imageSets, minSetCount, 'randomize');

% Separate set into training and validation data ==========================

[trainingSets, validationSets] = partition(imageSets, 0.5, 'randomize');

% Creating visual vocabulary and training an image category classifier ====
% 1. Extract SURF features from all images in all image categories.
% 2. Construct a visual vocabulary using K-means clustering.
% =========================================================================

k = 1;

for i = 1:size(trainingSets, 2)         % For every  training set of images
    for j = 1:trainingSets(1).Count     % For every image in a training set
        im{k} = read(trainingSets(i), j);
        k = k + 1;
    end
end

disp('Computing SURF features...');

for i = 1:trainingSets(1).Count
    detectFeatures = @(in) { detectSURFFeatures(in) };
    points         = cellfun(detectFeatures, im);
    extractAndTransposeFeatures = @(in, pts) extractFeatures(in, pts)';
    features = cellfun(extractAndTransposeFeatures, im, points, 'UniformOutput', false);
end

disp('Using K-means to create a 20 word vocabulary...');

nWords = 20;
[idx, centers] = kmeans([features{:}]', nWords);

disp('Creating histograms...');

histFeatures = cell(5,1);

for i = 1:size(im, 2)
    start = 1;
    histFeatures{i} = hist(idx(start:start + size(features{i}, 2)), nWords)';
    histFeatures{i} = histFeatures{i}./sum(histFeatures{i}); % Normalize
end

% The "Visual Word Occurrences" histogram =================================

% figure;
% bar(histFeatures{1});
% title('Visual Word Occurrences');
% xlabel('Visual word index');
% ylabel('Frequency of occurrence');
