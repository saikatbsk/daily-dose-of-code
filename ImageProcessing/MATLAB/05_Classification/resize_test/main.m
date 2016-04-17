clear; clc;

prompt = 'Test image? ';
str = input(prompt, 's');

% ====== original image ======

I = imread(str);

[dim1 dim2 chnl] = size(I);

for i = 1:chnl
    m(i) = mean(mean(I(:,:,i)));
end

m1 = mean(m(:));

% ====== resized image ======

Ir = imresize(I, [64 64]);

[dim1 dim2 chnl] = size(Ir);

for i = 1:chnl
    mr(i) = mean(mean(Ir(:,:,i)));
end

m2 = mean(mr(:));

% ====== plot ======

subplot(2, 1, 1); histogram(I); title('original');
subplot(2, 1, 2); histogram(Ir); title('resized');

fprintf('mean of original = %f , mean of resized = %f\n', m1, m2);
