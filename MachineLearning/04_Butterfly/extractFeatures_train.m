function moments = extractColorMoments_train(trainingimages)
    moments = [];

    for i = 1:size(trainingimages, 1)
        F = [];

        for j = 1:size(trainingimages, 2)
            img = trainingimages{i, j};

            [rows, cols, chnl] = size(img);

            %// 4 x 4 partitioning
            I1  = img(1:floor(rows/4), 1:floor(cols/4), :);
            I2  = img(1:floor(rows/4), floor(cols/4)+1:floor(cols/2), :);
            I3  = img(1:floor(rows/4), floor(cols/2)+1:floor(3*cols/4), :);
            I4  = img(1:floor(rows/4), floor(3*cols/4)+1:cols, :);
            I5  = img(floor(rows/4)+1:floor(rows/2), 1:floor(cols/4), :);
            I6  = img(floor(rows/4)+1:floor(rows/2), floor(cols/4)+1:floor(cols/2), :);
            I7  = img(floor(rows/4)+1:floor(rows/2), floor(cols/2)+1:floor(3*cols/4), :);
            I8  = img(floor(rows/4)+1:floor(rows/2), floor(3*cols/4)+1:cols, :);
            I9  = img(floor(rows/2)+1:floor(3*rows/4), 1:floor(cols/4), :);
            I10 = img(floor(rows/2)+1:floor(3*rows/4), floor(cols/4)+1:floor(cols/2), :);
            I11 = img(floor(rows/2)+1:floor(3*rows/4), floor(cols/2)+1:floor(3*cols/4), :);
            I12 = img(floor(rows/2)+1:floor(3*rows/4), floor(3*cols/4)+1:cols, :);
            I13 = img(floor(3*rows/4)+1:rows, 1:floor(cols/4), :);
            I14 = img(floor(3*rows/4)+1:rows, floor(cols/4)+1:floor(cols/2), :);
            I15 = img(floor(3*rows/4)+1:rows, floor(cols/2)+1:floor(3*cols/4), :);
            I16 = img(floor(3*rows/4)+1:rows, floor(3*cols/4)+1:cols, :);

            f1  = extractColorMoments(I1);
            f2  = extractColorMoments(I2);
            f3  = extractColorMoments(I3);
            f4  = extractColorMoments(I4);
            f5  = extractColorMoments(I5);
            f6  = extractColorMoments(I6);
            f7  = extractColorMoments(I7);
            f8  = extractColorMoments(I8);
            f9  = extractColorMoments(I9);
            f10 = extractColorMoments(I10);
            f11 = extractColorMoments(I11);
            f12 = extractColorMoments(I12);
            f13 = extractColorMoments(I13);
            f14 = extractColorMoments(I14);
            f15 = extractColorMoments(I15);
            f16 = extractColorMoments(I16);

            f = [f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15 f16];
            F = [F; f];
        end

        moments = [moments; mean(F)];
    end
end
