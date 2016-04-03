% Evaluate the classifier for all categories ==============================

confMatrix = evaluate(categoryClassifier, validationSets);

% Try the classifier on test images

img = read(validationSets(1), 17);
labelIdx = predict(categoryClassifier, img);
categoryClassifier.Labels(labelIdx);
subplot(1, 4, 1); imshow(img); title(categoryClassifier.Labels(labelIdx));

img = read(validationSets(2), 10);
labelIdx = predict(categoryClassifier, img);
categoryClassifier.Labels(labelIdx);
subplot(1, 4, 2); imshow(img); title(categoryClassifier.Labels(labelIdx));

img = read(validationSets(3), 21);
labelIdx = predict(categoryClassifier, img);
categoryClassifier.Labels(labelIdx);
subplot(1, 4, 3); imshow(img); title(categoryClassifier.Labels(labelIdx));

img = read(validationSets(4), 21);
labelIdx = predict(categoryClassifier, img);
categoryClassifier.Labels(labelIdx);
subplot(1, 4, 4); imshow(img); title(categoryClassifier.Labels(labelIdx));