% Try the classifier on multiple test images ==============================

i = 1;

while i <= size(validationSets, 2)
    % Read a random image from the validation set
    img = read(validationSets(i), randi(validationSets(1).Count, 1));

    % score is the negated average binary loss per class
    [labelIdx, score] = predict(categoryClassifier, img);

    subplot(2, size(validationSets, 2) / 2, i);
    img = insertText(img, [0 0], strcat('PREDICTED: ', categoryClassifier.Labels(labelIdx)), ...
        'FontSize', 18, 'BoxColor', 'red', 'BoxOpacity', .8, 'TextColor', 'white');
    img = insertText(img, [0 28], strcat('MATCH: ', num2str((1 - min(abs(score))) * 100), ' %'), ...
        'FontSize', 18, 'BoxColor', 'red', 'BoxOpacity', .8, 'TextColor', 'white');

    imshow(img);

    i = i + 1;
end
