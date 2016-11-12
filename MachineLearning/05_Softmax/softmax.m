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
