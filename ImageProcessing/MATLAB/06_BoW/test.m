% Create confusion matrix for evaluation ==================================

% confMatrix = evaluate(categoryClassifier, validationSets);

numberOfImageClasses = size(validationSets, 2);
numberOfImagesPerClass = validationSets(1).Count;

fprintf('\nCreating confusion matrix...\n\n');

confmat = [];

for i = 1:numberOfImageClasses
    fprintf('Looking at %d images from category %d...', numberOfImagesPerClass, i);
    scores = zeros(1, numberOfImageClasses);

    for j = 1:numberOfImagesPerClass
        img = read(validationSets(i), j);
        [labelIdx, score] = predict(categoryClassifier, img);
        [minval, index] = min(abs(score));
        scores(index) = scores(index) + 1;
    end

    confmat = [confmat; scores];
    fprintf('done\n');
end

confmat = [confmat] / numberOfImagesPerClass;

% Display confusion matrix ================================================

labels = {};

for i = 1:size(imageSets, 2)
    labels(i) = cellstr(imageSets(i).Description);
end

fprintf('\nKNOWN      | ');
for i = 1:size(labels, 2)
    fprintf('%10s ', strjoin(labels(i)));
end
fprintf('\n');

for i = 1:numberOfImageClasses
    fprintf('%10s | ', strjoin(labels(i)));
    for j = 1:numberOfImagesPerClass
        fprintf('%10.2f ', confmat(i, j));
    end
    fprintf('\n');
end

% Compute average accuracy ================================================

avg_acc = sum(diag(confmat)) / numberOfImageClasses;
avg_acc_p = round(avg_acc * 100);

fprintf('\nAverage accuracy = %d percent.\n', avg_acc_p);
