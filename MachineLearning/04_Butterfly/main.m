%% Butterfly category classification using Leeds Butterfly Dataset (v1.0)

clear; clc;

categories = { 'Danaus plexippus'  'Heliconius charitonius' 'Heliconius erato' 'Junonia coenia'   'Lycaena phlaea' ...
               'Nymphalis antiopa' 'Papilio cresphontes'    'Pieris rapae'     'Vanessa atalanta' 'Vanessa cardu' };

imagepath = 'leedsbutterfly/images';
segpath   = 'leedsbutterfly/segmentations';

imagesets     = readImageSet(imagepath);
segmentations = readImageSeg(segpath);

imagesPerSet  = 50;
maskedimages  = maskedImages(imagesets, imagepath, segmentations, segpath, imagesPerSet);

trainingimages = maskedimages(:, 1:30);
testimages     = maskedimages(:, 31:50);

trainingFeatures = extractFeatures_train(trainingimages);
[testFeatures labels] = extractFeatures_test(testimages);

result = knnsearch(trainingFeatures, testFeatures);

%// Confusion matrix
num_categories = size(categories, 2);
observation_per_category = size(testimages, 2);
conf_mat = confmat(labels, result, num_categories, observation_per_category);

%// Accuracy
acc = (size(labels, 1) - nnz([labels - result])) * 100 / size(labels, 1);

%// Display Results
displayResults;
