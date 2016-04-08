attempts = 0;
success  = 0;

for I = 1:size(validationSets, 2)
    for J = 1:validationSets(1).Count
        testImg = read(trainingSets(I), J);

        disp('Computing SURF features in test image...');

        points_test   = detectSURFFeatures(testImg);
        features_test = extractFeatures(testImg, points_test);

        disp('Creating histogram of word occurrences...');

        start = 1;
        histFeatures_test = hist(idx(start:start + size(features_test, 2)), nWords)';
        histFeatures_test = histFeatures_test./sum(histFeatures_test); % Normalize

        disp('Matching...');

        k = 1;

        for i = 1:size(trainingSets, 2)         % For every  training set of images
            for j = 1:trainingSets(1).Count     % For every image in a training set
                d(i, j) = sum(sqrt(histFeatures{k} - histFeatures_test).^2);
                % d(i, j) = norm(histFeatures{k} - histFeatures_test);
                k = k + 1;
            end

            D(i, 1) = mean(d(i, :));
        end

        minval = D(1);
        indexMatched = 1;

        for i = 2:size(D, 1)
            if D(i) < minval
                minval = D(i);
                indexMatched = i;
            end
        end

        attempts = attempts + 1;

        if indexMatched == I
            disp('>>> Success!');
            success = success + 1;
        else
            display('>>> Failed!');
        end
    end
end

[attempts]
[success]
