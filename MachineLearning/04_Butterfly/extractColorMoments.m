function moments = extractColorMoments(image)
    imgR  = image(:, :, 1);
    imgG  = image(:, :, 2);
    imgB  = image(:, :, 3);

    meanR = mean2(imgR);
    meanG = mean2(imgG);
    meanB = mean2(imgB);

    stdR  = std2(imgR);
    stdG  = std2(imgG);
    stdB  = std2(imgB);

    moments = [meanR meanG meanB stdR stdG stdB];
end
