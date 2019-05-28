clc;
clear all;
close all;

t = 0 : 0.001 : 1;
a = 5;
fm = input('Enter the frequency of message signal: ');
fc = input('Enter the frequency of carrier signal: ');
mi = input('Enter the modulation index: ');

sm = a*sin(2*pi*fm*t);
sc = a*sin(2*pi*fc*t);

sam = (a + mi*sm).*sin(2*pi*fc*t);

figure(73050);
subplot(3, 1, 1);
plot(t, sm);
title('Message Signal');

subplot(3, 1, 2);
plot(t, sc);
title('Carrier Signal');

subplot(3, 1, 3);
plot(t, sam);
title('AM Signal');