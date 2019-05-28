clc;
clear all;
close all;

t = 0 : 0.001 : 1;
fm = input('Enter the frequency of message signal: ');
fc = input('Enter the frequency of carrier signal: ');
amp = input('Enter amplitude: ');

figure(73050);
m = square(2*pi*fm*t);
subplot(3, 1, 1);
plot(t, m);
axis([0 1 -2 2]);
title('Message Signal');

c = amp.*sin(2*pi*fc*t);
subplot(3, 1, 2);
plot(t, c);
title('Carrier Signal');

w = c.*m;
subplot(3, 1, 3);
plot(t, w);
title('PSK Signal');