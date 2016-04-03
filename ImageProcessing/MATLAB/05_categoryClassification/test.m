% Evaluate the classifier for all categories ==============================

% confMatrix = evaluate(categoryClassifier, validationSets);

% Try the classifier on test images

img = read(validationSets(1), 10);
labelIdx = predict(categoryClassifier, img);
categoryClassifier.Labels(labelIdx);
subplot(1, 4, 1); imshow(img); title(categoryClassifier.Labels(labelIdx));
