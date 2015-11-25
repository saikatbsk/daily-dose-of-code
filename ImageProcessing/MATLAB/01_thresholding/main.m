rgb = imread('src.png');

bw1 = im2bw(rgb, 0.2);
bw2 = im2bw(rgb, 0.4);
bw3 = im2bw(rgb, 0.6);

subplot(2, 2, 1), imshow(rgb); t(1) = title('Original Image');
subplot(2, 2, 2), imshow(bw1); t(2) = title('0.2 Threshold');
subplot(2, 2, 3), imshow(bw2); t(3) = title('0.4 Threshold');
subplot(2, 2, 4), imshow(bw3); t(4) = title('0.6 Threshold');

set(t, 'Position', [180 280], 'VerticalAlignment', 'top');