clc
clear all
close all

num = [1, 0, 2, 3, 0.7, 0, 1.7];
den = [1, 0.4, 0.6, 1.4, 0, 1, 2];

[z, p, k] = tf2zp(num, den);

zplane(z, p);