clc
clear all;
close all;

t = -2.5 : 0.0001 : 2;
y = heaviside(t);

figure(73050);
plot(t, y), grid;
axis([-2 2 -1 2]);
title('Unit Step Signal');
xlabel('Time');
ylabel('Amplitude');