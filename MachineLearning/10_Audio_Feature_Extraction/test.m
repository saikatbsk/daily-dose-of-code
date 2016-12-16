clear; clc;

fn = 'sounds/cow/01.wav';
info = audioinfo(fn)
[y, fs] = audioread(fn);
mono = (y(:, 1)+y(:, 2)) ./ max(abs(y(:, 1)+y(:, 2)));
plot(mono)
