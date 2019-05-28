clc
clear all;
close all;

t = 0 : 0.1 : 5;
m = 1;
r = m*t;

figure(73050);
plot(t, r);
axis([0, 4, 0, 5]);
title('Unit Ramp Signal');
xlabel('Time');
ylabel('r(t)');