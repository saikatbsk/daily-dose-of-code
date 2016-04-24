% Reading a color image %
src = imread('tree.png');

% Convert to L*a*b* %
cform = makecform('srgb2lab');
lab = applycform(src, cform);

% Classify the colors in 'a*b*' space using K-Means clustering %
ab = double(lab(:,:,2:3));
nrows = size(ab,1);
ncols = size(ab,2);
ab = reshape(ab, nrows * ncols, 2);

nColors = 3;
[cluster_idx, cluster_center] = kmeans(ab, nColors, 'distance', 'sqEuclidean', 'Replicates',3); % repeat the clustering 3 times to avoid local minima %

% Label every pixel in the image using the results from K-Means %
pixel_labels = reshape(cluster_idx, nrows, ncols);

% Create images that segment the original image by color %
segmented_images = cell(1, 3);
rgb_label = repmat(pixel_labels, [1 1 3]);

for k = 1 : nColors
    color = src;
    color(rgb_label ~= k) = 0;
    segmented_images{k} = color;
end

% Segment the blue river into a separate image %
mean_cluster_value = mean(cluster_center, 2);
[tmp, idx] = sort(mean_cluster_value);
blue_cluster_num = idx(1);

L = lab(:,:,1);
blue_idx = find(pixel_labels == blue_cluster_num);
L_blue = L(blue_idx);
is_light_blue = im2bw(L_blue, graythresh(L_blue));

labels = repmat(uint8(0), [nrows ncols]);
labels(blue_idx(is_light_blue == false)) = 1;
labels = repmat(labels, [1 1 3]);
blue_river = src;
blue_river(labels ~= 1) = 0;

% Display images %
subplot(3, 3, 1), imshow(src); title('Original image');
subplot(3, 3, 2), imshow(lab); title('L*a*b*');
subplot(3, 3, 3), imshow(pixel_labels, []); title('Image labeled by cluster index');
subplot(3, 3, 4), imshow(segmented_images{1}); title('Objects in cluster 1');
subplot(3, 3, 5), imshow(segmented_images{2}); title('Objects in cluster 2');
subplot(3, 3, 6), imshow(segmented_images{3}); title('Objects in cluster 3');
subplot(3, 3, 7), imshow(blue_river); title('Blue river');