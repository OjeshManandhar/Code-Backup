clc
clear all;
close all;

a = 1;
t = -10 : 0.0005 : 10;
x = a*square(t);

figure(73050);
plot(t, x);
axis([-5 5 -2 2]);
title('Square Wave');
xlabel('Time');
ylabel('Amplitude');