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

%// Graphical output
res = reshape(result, 20, [])';
lbl = reshape(labels, 20, [])';

for i = 1:size(categories, 2)
    idx = randi([1 size(testimages, 2)]);
    img = testimages{i, idx};

    if size(img, 1) > size(img, 2)
        img = imresize(img, [200, NaN]);
    else
        img = imresize(img, [NaN, 200]);
    end

    pa = ceil((200 - size(img, 1))/2);
    pb = ceil((200 - size(img, 2))/2);

    img = padarray(img, [pa pb]);

    subplot(2, size(categories, 2)/2, i);
    imshow(img);

    if res(i, idx) == lbl(i, idx)
        title(char(categories(res(i, idx))), 'FontSize', 10, 'FontWeight', 'normal');
    else
        title(char(categories(res(i, idx))), 'FontSize', 10, 'FontWeight', 'normal', 'Color', 'red');
    end
end
