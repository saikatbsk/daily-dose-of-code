img = imread('testset/ad.png');
%img = imresize(img, [400 400]);
ca = part_image(img);

rows = size(ca, 1);
cols = size(ca, 2);

index = 1;

for p = 1:rows
    for q = 1:cols
        tmpCell = ca(p, q);
        mat = [tmpCell{1}];

        subplot(rows, cols, index); imshow(mat);
        index = index + 1;
    end
end
