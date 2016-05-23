% Tests the object classifier threshold ===================================

% Defining path and loading dataset =======================================

imagesets_unknown = [imageSet(fullfile(datasetFolderRoot, 'anchor')), ...
    imageSet(fullfile(datasetFolderRoot, 'barrel')), ...
    imageSet(fullfile(datasetFolderRoot, 'okapi')), ...
    imageSet(fullfile(datasetFolderRoot, 'pagoda')) ...
    imageSet(fullfile(datasetFolderRoot, 'electric_guitar')), ...
    imageSet(fullfile(datasetFolderRoot, 'lotus')), ...
    imageSet(fullfile(datasetFolderRoot, 'pyramid')), ...
    imageSet(fullfile(datasetFolderRoot, 'brain'))];

THRESH = 0.102;     % object classifier threshold

num_cat    = size(validationSets, 2);
num_images = validationSets(1).Count;

count_unknownclass = 0;

fprintf('\nTesting calculated threshold...\n\n');

fprintf('\nChecking %d images from %d unknown categories...', num_images, num_cat);

for i = 1:num_cat
    for j = 1:num_images
        img = read(imagesets_unknown(i), j);

        % score is the negated average binary loss per class
        [labelIdx, score] = predict(categoryClassifier, img);

        if min(abs(score)) > THRESH
            count_unknownclass = count_unknownclass + 1;
        end
    end
end

fprintf('done\n');
fprintf('%d images out of %d are predicted to be unknown.\n', count_unknownclass, num_images * num_cat);
