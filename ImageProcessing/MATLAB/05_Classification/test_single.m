prompt = 'Test image? ';
str = input(prompt, 's');

[testpath, testfilename, ext] = fileparts(str);

src = imread(str);

img = imresize(src, target_dim_of_image);

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

predictedCategory = strcat(labels(IndexOfMinSSD));

test_title = str;
match_title = strcat('trainingset/', predictedCategory, '.png');
subplot(2, 1, 1); imshow(char(test_title)); title(strcat('test image: ', test_title));
subplot(2, 1, 2); imshow(char(match_title)); title(strcat('matched with: ', match_title));
