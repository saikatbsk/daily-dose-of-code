clear; clc;

nImages = 0;
fileId = fopen('trainingset.txt', 'r');

labels = cell(100, 1);

i = 1;

while ~feof(fileId)
    line = fgets(fileId);                % Read image filename from fileId
    [path, name, ext] = fileparts(line); % Break filename into parts for future use

    labels{i} = strcat(name);

    img = imread(strcat(line));

    [rows, cols, chnls] = size(img);
    ca = part_image(img);

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
