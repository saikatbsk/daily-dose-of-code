im = imread('mango2.jpg');
imFlat = double(reshape(im, size(im,1) * size(im,2), 3));

K = 2;
[kIDs, kC] = kmeans(imFlat, K, 'Display', 'iter', 'MaxIter', 1000, 'Start', 'sample');

imOut = reshape(uint8(kIDs), size(im,1), size(im,2));

mask = imOut-1;
imOrig = imread('mango1.jpg');
mask = imresize(mask, [size(imOrig, 1), size(imOrig, 2)]);

masked1 = bsxfun(@times, imOrig, cast(mask, class(imOrig)));
masked2 = bsxfun(@times, imOrig, cast(~mask, class(imOrig)));

imwrite(masked1, 'out1.jpg');
imwrite(masked2, 'out2.jpg');

subplot(1, 2, 1); imshow(masked1);
subplot(1, 2, 2); imshow(masked2);