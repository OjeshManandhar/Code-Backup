clc;
clear all;
close all;

t = 0 : 0.0001 : 0.1;
fm = input('Enter the frequency of message signal: ');
fc = input('Enter the frequency of carrier signal: ');
mi = input('Enter modulation index: ');

sm = sin(2*pi*fm*t);
sc = sin(2*pi*fc*t);
sfm = sin(2*pi*fc*t + mi.*sin(2*pi*fm*t));

figure(73050);
subplot(3, 1, 1);
plot(t, sm);
title('Message Signal');

subplot(3, 1, 2);
plot(t, sc);
title('Carrier Signal');

subplot(3, 1, 3);
plot(t, sfm);
title('FM Signal');