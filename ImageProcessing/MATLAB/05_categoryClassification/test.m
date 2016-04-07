% Evaluate the classifier for all categories ==============================

confMatrix = evaluate(categoryClassifier, validationSets);

% Try the classifier on test images =======================================

img = read(validationSets(1), 1);
[labelIdx, score] = predict(categoryClassifier, img);
imshow(img); title(categoryClassifier.Labels(labelIdx));

% for i = 1:4
%     for j = 1:10
%         img = read(validationSets(i), j);
%         labelIdx = predict(categoryClassifier, img);
%         subplot(2, 5, j); imshow(img); title(categoryClassifier.Labels(labelIdx));
%     end
%     pause;
% end
