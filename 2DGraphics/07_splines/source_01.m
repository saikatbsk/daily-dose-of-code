close all

X = (-10 : 2 : 10)';
Y = sign(X);

plot(X, Y, 'b*');

O = 7;
H = ones(length(X), O + 1);

for i = 2:(O + 1)
  H(:, i) = X.^(i - 1);
end

Astar = inv(H' * H) * H' * Y;

Xsmooth = linspace(X(1), X(end), 100);
Hs = ones(length(Xsmooth), O + 1);

for i = 2:(O + 1)
  Hs(:, i) = Xsmooth.^(i - 1);
end

Ytilda = Hs * Astar;

hold on

plot(Xsmooth, Ytilda, 'r-');

% Linear Splines
% m = (y1 - y0) / (x1 - x0)
% y = m(x - x0) + y0

for i = 1:length(X) - 1
  m = (Y(i + 1) - Y(i)) / (X(i + 1) - X(i));
  xspline = linspace(X(i), X(i + 1), 10);
  yspline = m * (xspline - X(i)) + Y(i);
  plot(xspline, yspline, 'g-');
end