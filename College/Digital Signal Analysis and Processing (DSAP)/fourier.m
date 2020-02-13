clc
clear all
close all

x = [0, 1, 2, 3];
y = fft(x, 4);

subplot(2, 1, 1);
stem(real(y));

subplot(2, 1, 2);
stem(imag(y));