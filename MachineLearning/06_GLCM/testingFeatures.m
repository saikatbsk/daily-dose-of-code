function all_desc_test = trainingFeatures(testset)
    all_desc_test = [];

    for i = 1:size(testset, 1)
        for j = 1:size(testset, 2)
            img  = imread(char(testset(i, j)));
            gray = rgb2gray(img);

            offsets    = [0 1; -1 1; -1 0; -1 -1];
            properties = glcmProperties(gray, offsets);

            all_desc_test = cat(1, all_desc_test, properties);
        end
    end
end
