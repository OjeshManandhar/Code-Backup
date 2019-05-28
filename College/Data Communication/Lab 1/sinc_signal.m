clc
clear all;
close all;

x = -5 : 0.001 : 5;
y = sinc(x);

figure(73050);
plot(x, y), grid;
axis([-6 6 -1 2]);
title('Sinc Signal');
xlabel('Time');
ylabel('Amplitude');