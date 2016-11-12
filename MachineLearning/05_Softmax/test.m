clear; clc;

y = [1, 2, 3, 6; 2, 4, 5, 6; 3, 8, 7, 6];
s = softmax(y);

subplot(2, 1, 1); bar(y'); ylabel('scores');
subplot(2, 1, 2); bar(s'); ylabel('probabilities');
