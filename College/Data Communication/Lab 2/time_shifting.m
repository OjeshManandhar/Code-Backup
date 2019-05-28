clc;
clear all;
close all;

n1 = input('Enter amount to be delayed (n1): ');
n2 = input('Enter amount to be advanced (n2): ');
n = -2 : 2;
x = [-2 3 0 1 5];

figure(73050);
subplot(3, 1, 1);
stem(n, x);
title('Original Signal');

m = n - n1;
subplot(3, 1, 2);
stem(m, x);
title('Delayed Signal x[n - n1]');

m = n + n1;
subplot(3, 1, 3);
stem(m, x);
title('Advanced Signal x[n + n1]');