%% Create confusion matrix

function conf_mat = confmat(labels, result, num_categories, observation_per_category)
    conf_mat = zeros(num_categories);

    for i = 1:(num_categories * observation_per_category)
        x = labels(i);
        y = result(i);

        conf_mat(x, y) = conf_mat(x, y) + 1;
    end

    conf_mat = conf_mat/observation_per_category;
end
