clc
clear all
close all

n = 0 : 10;
x = 0.5 .* n;
h = ones(1, 11);
y = conv(x, h);

stem(y);