clear; clc;

nImages = 0;
fileId = fopen('trainingset.txt', 'r');

labels = cell(nImages, 1);

target_height_of_image = 64;
target_height_of_block = 2;

target_dim_of_image = [target_height_of_image target_height_of_image];
number_of_rows_needed = target_height_of_image / target_height_of_block;
target_dim_of_each_block = [ones(1, number_of_rows_needed) * target_height_of_block];

i = 1;

while ~feof(fileId)
    line = fgets(fileId);                % Read image filename from fileId
    [path, name, ext] = fileparts(line); % Break filename into parts for future use

    labels{i} = strcat(name);

    img = imread(strcat(line));

    [dim1 dim2] = size(img);
    dim_ratio_orig(i, 1) = dim1 / dim2;

    img = imresize(img, target_dim_of_image);

    [rows, cols, chnls] = size(img);
    ca = mat2cell(img, target_dim_of_each_block, target_dim_of_each_block, chnls);

    for p = 1:size(ca, 1)
        for q = 1:size(ca, 2)
            tmpCell = ca(p, q);
            mat = [tmpCell{1}];

            % We need to determine mean for all 3 channels
            for r = 1:chnls
                Y = mat(:, :, r);

                m(r) = mean(mean(Y));
            end
            means(p, q, i) = mean(m(:));
        end
    end

    i = i + 1;
    nImages = nImages + 1;
end

fclose(fileId);
