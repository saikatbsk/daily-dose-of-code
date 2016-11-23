clear; clc;

rootpath    = 'img';
classnames  = {'1' '2' '3'};
imagesets   = imageRead(rootpath, classnames, 7);
trainingset = imagesets(:, 1:4);
testset     = imagesets(:, 5:7);

all_desc_sample = {};
all_desc_mean   = [];
all_desc_test   = [];

offsets = [-1 0; 1 0; 0 -1; 0 1];

[all_desc_mean all_desc_sample] = trainingFeatures(trainingset, offsets);
all_desc_test = testingFeatures(testset, offsets);

% hold on;
% for i = 1:size(trainingset, 1)
%     desc = all_desc_mean(i, :);
%     plot(desc);
% end

knnsearch(all_desc_mean, all_desc_test)
