clc
clear all
close all;

num = [0.002, -0.008, 0.013, -0.008, 0.002];
den = [1.2, 3, 0.213, 3, 1.2];
w = 20;

x = freqz(num, den, w);

subplot(2, 1, 1);
plot(abs(x));

subplot(2, 1, 2);
plot(angle(x));