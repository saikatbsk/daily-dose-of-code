%% ========================================================================
%% This is the main project file responsible for - (1) loading the dataset,
%% (2) extracting features, (3) creating a codebook, (4) generating feature
%% histogram, and (5) classification.
%%
%% Tested with GNU Octave 4.0.2 (URL: https://www.gnu.org/software/octave/)
%% ========================================================================

%% Load training and testing dataset ======================================

clear; clc;

fprintf('Loading dataset..'); fflush(stdout);

train_root = 'dataset/train/';
test_root  = 'dataset/test';
class_names = {'accordion', 'airplanes', 'leopards', 'wheelchair'};

for i = 1:length(class_names)
    fn = { dir(fullfile(train_root, char(class_names(i)), '*.jpg')).name };

    for j = 1:length(fn)
        % training_set : M*N --> M=image category, N=samples per category
        training_set(i, j) = fullfile(train_root, char(class_names(i)), fn(j));
    end
end

for i = 1:length(class_names)
    fn = { dir(fullfile(test_root, char(class_names(i)), '*.jpg')).name };

    for j = 1:length(fn)
        % test_set : M*N --> M=image category, N=samples per category
        test_set(i, j) = fullfile(test_root, char(class_names(i)), fn(j));
    end
end

fprintf('Done\n\n'); fflush(stdout);

%% Extract SURF features from training set ================================

% all_des        - All the SURF descriptors (m*64)
% all_des_sample - All the SURF descriptors per sample (1*n cell)
% class_label    - Class label for each surf descriptor (m*1)

[all_des all_des_sample class_label] = extractFeatures(training_set);

%% Creating codebook using K-mean clustering ==============================

N = 500;    % Number of clusters

centers = createKmeanClusters(all_des, all_des_sample, N);
