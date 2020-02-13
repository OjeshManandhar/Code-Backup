clc 
clear all
close all

x = [1, -2, 1, 1];
h = [1, 0, 1, 1];

y = conv(x, h);

subplot(3, 3, 1);
stem(x);

subplot(3, 3, 5);
stem(h);

subplot(3, 3, 9);
stem(y);