fp = fopen('trainingset.txt', 'r');

testLabels = cell(nImages, 1);

testIndex = 1;

while ~feof(fp)
    l = fgets(fp);
    
    testdata = strcat(l);

    img = imread(strcat(testdata));
    img = imresize(img, [64 64]);

    caTest = mat2cell(img, [16 16 16 16], [16 16 16 16], chnls);
    meansTest = zeros(size(caTest, 1), size(caTest, 2));

    for p = 1:size(caTest, 1)
        for q = 1:size(caTest, 2)
            tmpCell = caTest(p, q); % One cell containing 16x16x3 matrix
            mat = [tmpCell{1}]; % mat becomes a 16x16x3 matrix
        
            % We need to determine mean for all 3 channels
            for r = 1:chnls
                Y = mat(:, :, r); % Every k-th dimension is a 16x16 matrix
    
                m = mean(mean(Y));
                meansTest(p, q) = m;
            end
        end
    end

    % Find sum of squared difference between mean values computed from training
    % image and test image
    
    for I = 1:nImages
        a = means(:, :, I);
        b = meansTest(:,:);
        D(I) = sumsqr(a-b)
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

    actualCategory = strcat(labels(testIndex));
    predictedCategory = strcat(labels(IndexOfMinSSD));
    
    result(testIndex, 1) = [actualCategory];
    result(testIndex, 2) = [predictedCategory];
    
    testIndex = testIndex + 1;
    
    disp(result);
end

fclose(fp);