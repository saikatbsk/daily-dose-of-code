clear; clc;

fileId = fopen('filenames.txt', 'r');

numberOfFiles = 70;              % Number of files to be opened
means = zeros(1, numberOfFiles); % Create an empty array to store the means
labels = cell(numberOfFiles);    % Create an empty cell to store the labels
i = 1;

while (~feof(fileId) && i <= numberOfFiles)
    line = fgets(fileId);                   % Read image filename from fileID
    [path, name, ext] = fileparts(line);    % Break filename into parts for future use
    
    img = imread(strcat(line));
    img = rgb2hsv(img);
    img = img(:, :, 1);
    process;
    
    means(i) = mean(mean(img));
    labels{i} = strcat(name);
    
    i = i + 1;
end

fclose(fileId);