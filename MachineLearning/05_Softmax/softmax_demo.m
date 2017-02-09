% Softmax demo

function main
    y = [1, 2, 3, 6; 2, 4, 5, 6; 3, 8, 7, 6];
    s = softmax(y);

    subplot(2, 1, 1); bar(y'); ylabel('scores');
    subplot(2, 1, 2); bar(s'); ylabel('probabilities');
end

% The softmax function turns scores into probabilities.
% General algorithm,
%       a = softmax(n) = exp(n)/sum(exp(n))

function s = softmax(y)
    sumofexpt = sum(exp(y));
    exponents = exp(y);
    s = [];

    for i = 1:size(exponents, 2)
        s = [s exponents(:, i)/sumofexpt(i)];
    end
end
