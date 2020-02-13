clc
clear all
close all

y = [6.0000, -2.0000 + 2.0000i, -2.0000, -2.0000 - 2.0000i]
x = ifft(y, 4)

stem(x);
