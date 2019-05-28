clc
clear all;
close all;

x = [-pi : 0.1 : pi];
y = sin(x);

figure(73050);
plot(x, y), grid;
title('Sine wave');
xlabel('Time');
ylabel('Amplitude');