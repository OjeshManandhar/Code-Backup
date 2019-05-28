clc;
clear all;
close all;

n = -1 : 2;
x = [3 -1 0 -4];

figure(73050);
subplot(2, 1, 1);
stem(n, x);
title('Original Signal');
axis([-3 3 -5 5]);
c = fliplr(x);
y = fliplr(-n);

subplot(2, 1, 2);
stem(y, c);
axis([-3 3 -5 5]);
title('Reversed Signal');