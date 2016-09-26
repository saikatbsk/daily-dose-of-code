function maskedimages = maskedImages(imagesets, imagepath, segmentations, segpath, imagesPerSet)
    maskedimages = {};
    numsets = size(imagesets, 2);

    for i = 1:numsets
        for j = 1:imagesPerSet
            srcfn = fullfile(imagepath, imagesets{i}(j).name);
            segfn = fullfile(segpath, segmentations{i}(j).name);
            src   = imread(srcfn);
            mask  = imread(segfn);
            final = bsxfun(@times, src, cast(mask, class(src)));

            stats = regionprops(mask, 'BoundingBox');
            final = imcrop(final, stats.BoundingBox);

            maskedimages{i, j} = final;
        end
    end
end
