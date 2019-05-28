clc;
clear all;
close all;

t = -5 : 0.0001 : 5;
x = tripuls(t, 2);

figure(73050);
subplot(3, 1, 1);
plot(t, x), grid;
title('Original Triangular Signal');

x = tripuls(2*t, 2);
subplot(3, 1, 2);
plot(t, x), grid;
title('Triangular Signal scaled by 2');

x = tripuls(t/2, 2);
subplot(3, 1, 3);
plot(t, x), grid;
title('Triangular Signal scaled by 1/2');