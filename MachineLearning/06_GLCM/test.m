clear; clc;

rootpath    = 'img';
classnames  = {'grass' 'wood'};
imagesets   = imageRead(rootpath, classnames, 10);
trainingset = imagesets(:, 1:6);
testset     = imagesets(:, 7:10);

all_desc_sample = {};
all_desc_mean   = [];
all_desc_test   = [];

[all_desc_mean all_desc_sample] = trainingFeatures(trainingset);
all_desc_test = testingFeatures(testset);

% hold on;
% for i = 1:size(trainingset, 1)
%     desc = all_desc_mean(i, :);
%     plot(desc);
% end

knnsearch(all_desc_mean, all_desc_test)
