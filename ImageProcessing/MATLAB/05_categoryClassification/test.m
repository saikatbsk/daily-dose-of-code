% Evaluate the classifier for all categories ==============================

% validationSetPath = '/home/saikat/Workspace/Datasets/miscObjects';
% validationSets = [imageSet(fullfile(validationSetPath, 'umbrella')), ...
    % imageSet(fullfile(validationSetPath, 'camera')), ...
    % imageSet(fullfile(validationSetPath, 'dolphin')), ...
    % imageSet(fullfile(validationSetPath, 'airplanes'))]

% confMatrix = evaluate(categoryClassifier, validationSets);

% Try the classifier on test images

for i = 1:4
    for j = 1:20
        img = read(validationSets(i), j);
        labelIdx = predict(categoryClassifier, img);
        categoryClassifier.Labels(labelIdx);
        subplot(4, 5, j); imshow(img); title(categoryClassifier.Labels(labelIdx));
    end
    pause;
end