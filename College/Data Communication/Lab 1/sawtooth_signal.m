clc;
clear all;
close all;

t = -10 : 0.0005 : 10;
x = sawtooth(t);

figure(73050);
plot(t, x);
axis([-10 5 -3 3]);
title('Sqwtooth Wave');
xlabel('Time');
ylabel('Amplitude');