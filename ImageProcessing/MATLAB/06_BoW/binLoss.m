function minloss = binLoss(classifier, imagesets, count)
    minloss = [];

    num_Cat_imset = size(imagesets, 2);
    min_setCount  = min([imagesets.Count]);
    num_Cat_class = classifier.NumCategories;

    if (min_setCount < count)
        fprintf('>>> Number of images in each image set must be equal to or greater than count.\n');
    elseif (num_Cat_class ~= num_Cat_imset)
        fprintf('>>> Number of categories in imagesets must be equal to number of categories in classifier.\n');
    else
        for i = 1:num_Cat_imset
            fprintf('Looking at %d images from category %d...', num_Cat_imset, i);

            for j = 1:count
                img = read(imagesets(i), j);
                [idx, score] = predict(classifier, img);

                minloss = [minloss min(abs(score))];
            end

            fprintf('done\n');
        end
    end
end
