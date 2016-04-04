img = imread(strcat(testdata));
img = rgb2hsv(img);
img = img(:, :, 1);
process;

mean_test = mean(mean(img));

diff = zeros(1, numberOfFiles);

for i = 1:numberOfFiles
    diff(i) = abs(means(i) - mean_test);
end

% Check for minimum difference

min = diff(1);
indexMatched = 1;

for i = 2:numberOfFiles
    if diff(i) < min
        min = diff(i);
        indexMatched = i;
    end
end

fprintf('Test data matched with %s. Diff = %f\n', char(labels(indexMatched)), diff(indexMatched));