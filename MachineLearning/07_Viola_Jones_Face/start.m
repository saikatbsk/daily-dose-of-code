clear; clc;

fd = vision.CascadeObjectDetector;
im = imread('most_intelligent_picture_ever_taken.jpg');
bb = step(fd, im);

IFaces = insertObjectAnnotation(im, 'rectangle', bb, 'Face');
imshow(IFaces); title('Detected Faces');
