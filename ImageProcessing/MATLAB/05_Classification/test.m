fp = fopen('testset.txt', 'r');

testLabels = cell(100, 1);

testIndex = 1;
success   = 0;

while ~feof(fp)
    l = fgets(fp);
    [testpath, testfilename, ext] = fileparts(l); % Break filename into parts for future use

    testLabels{testIndex} = strcat(testfilename);

    testdata = strcat(l);

    img = imread(strcat(testdata));

    img = imresize(img, target_dim_of_image);

    caTest = mat2cell(img, target_dim_of_each_block, target_dim_of_each_block, chnls);
    meansTest = zeros(size(caTest, 1), size(caTest, 2));

    for p = 1:size(caTest, 1)
        for q = 1:size(caTest, 2)
            tmpCell = caTest(p, q);
            mat = [tmpCell{1}];

            % We need to determine mean for all 3 channels
            for r = 1:chnls
                Y = mat(:, :, r);

                m(r) = mean(mean(Y));
            end
            meansTest(p, q) = mean(m(:));
        end
    end

    % Find sum of squared difference between mean values computed from training
    % image and test image

    for I = 1:nImages
        a = means(:, :, I);
        b = meansTest(:,:);
        D(I) = sumsqr(a-b);
    end

    % Find minimum squared difference

    minssd = D(1);
    IndexOfMinSSD = 1;

    for I = 2:nImages
        if minssd > D(I)
            minssd = D(I);
            IndexOfMinSSD = I;
        end
    end

    actualCategory = strcat(testLabels(testIndex));     % Actual image being tested
    predictedCategory = strcat(labels(IndexOfMinSSD));  % Test image matched with image in the training set

    result(testIndex, 1) = [actualCategory];
    result(testIndex, 2) = [predictedCategory];

    if strcmp(result(testIndex, 1), result(testIndex, 2))
        fprintf('%s correctly matched with: %s\n', char(result(testIndex, 1)), char(result(testIndex, 2)));
        success = success + 1;
    else
        fprintf('%s wrongly matched with: %s\n', char(result(testIndex, 1)), char(result(testIndex, 2)));

        test_title = strcat('testset/', predictedCategory, '.png');
        match_title = strcat('trainingset/', actualCategory, '.png');
        %subplot(2, 1, 1); imshow(char(test_title)); title(strcat('test image: ', test_title));
        %subplot(2, 1, 2); imshow(char(match_title)); title(strcat('matched with: ', match_title));
        %pause;
    end

    testIndex = testIndex + 1;
end

success_rate = (success / nImages) * 100;

fprintf('%d out of %d images identified successfully.\n', success, nImages);
fprintf('Success rate = %2.2f percent.\n', success_rate);

fclose(fp);
