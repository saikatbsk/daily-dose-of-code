function all_desc_test = trainingFeatures(testset, offsets)
    all_desc_test = [];

    for i = 1:size(testset, 1)
        for j = 1:size(testset, 2)
            img  = imread(char(testset(i, j)));

            properties = glcmProperties(img, offsets);

            all_desc_test = cat(1, all_desc_test, properties);
        end
    end
end
