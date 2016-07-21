src  = imread("tree.png");
gray = rgb2gray(src);
bw   = edge(gray, "Canny");
imshow(bw);