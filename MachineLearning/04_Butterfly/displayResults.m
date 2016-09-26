% Display Results

for i = 1:((size(categories, 2) * 20) / 2)
    fprintf(' ');
end

fprintf('PREDICTED\n');
fprintf('KNOWN                | ');

%// Table Headers
for i = 1:num_categories
    th = char(categories(i));

    if length(th) > 20
        th = strcat(th(1:18), '..');
    end

    fprintf('%20s ', th);
end

fprintf('\n');

for i = 1:((size(categories, 2) + 1) * 21) + 1
    fprintf('-');
end

fprintf('\n');

%// Row Headers and Data
for i = 1:size(conf_mat, 1)
    rh = char(categories(i));

    if length(rh) > 20
        rh = strcat(rh(1:18), '..');
    end

    fprintf('%20s | ', rh);

    for j = 1:size(conf_mat, 1)
        fprintf('%20.2f ', conf_mat(i, j));
    end

    fprintf('\n');
end

fprintf('\n');
