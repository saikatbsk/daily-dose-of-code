src  = imread('flower.jpg');
mask = imread('mask.pgm');
masked = bsxfun(@times, src, cast(mask, class(src)));

bd = [];
boundaries = bwboundaries(mask);
for i = 1:length(boundaries)
    bd = [bd; boundaries{i, 1}];
end
bd = dpsimplify(bd, 1);

center = round([mean(bd(:, 2)) mean(bd(:, 1))]);
dists  = euclideanDistance(bd, center);

figure(1);
hold on
plot(bd(:, 2), bd(:, 1), 'b.', 'LineWidth', 2);
plot(center(1), center(2), 'rx', 'LineWidth', 2, 'MarkerSize', 10)
