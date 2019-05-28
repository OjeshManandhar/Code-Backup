clc
clear all;
close all;

t = 0 : 0.01 : 5;
a = 2;
y = exp(a*t);

figure(73050);
plot(t, y);
axis([0 2 0 60]);
title('Exponential Signal');
xlabel('Time');
ylabel('y(t)');