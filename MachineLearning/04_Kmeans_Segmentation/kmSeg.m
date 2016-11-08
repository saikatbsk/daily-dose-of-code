imSrc  = imread('img/orange_03.jpg');

imInp  = imresize(imSrc, .15);
imFlat = double(reshape(imInp, size(imInp, 1) * size(imInp, 2), 3));

K = 2;
[kIdx kC] = kmeans(imFlat, K, 'Display', 'iter', 'MaxIter', 1000, 'Start', 'sample');

imMask = (reshape(uint8(kIdx), size(imInp, 1), size(imInp, 2))) - 1;
imMask = imresize(imMask, [size(imSrc, 1), size(imSrc, 2)]);

imOut1 = bsxfun(@times, imSrc, cast(extractNLargestBlobs((imMask), 1), class(imSrc)));
imOut2 = bsxfun(@times, imSrc, cast(extractNLargestBlobs((~imMask), 1), class(imSrc)));

subplot(1, 2, 1); imshow(imOut1);
subplot(1, 2, 2); imshow(imOut2);
