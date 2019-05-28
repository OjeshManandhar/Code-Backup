clc;
clear all;
close all;

t = 0 : 0.001 : 1;
fm = input('Enter the frequency of message signal: ');
fc1 = input('Enter the frequency of 1st carrier signal: ');
fc2 = input('Enter the frequency of 2nd carrier signal: ');
amp = input('Enter amplitude: ');
amp = amp/2;

figure(73050);
m = amp.*square(2*pi*fm*t) + amp;
subplot(4, 1, 1);
plot(t, m);
axis([0 1 -1 5]);
title('Message Signal');

c1 = amp.*sin(2*pi*fc1*t);
subplot(4, 1, 2);
plot(t, c1);
title('1st Carrier Signal');

c2 = amp.*sin(2*pi*fc2*t);
subplot(4, 1, 3);
plot(t, c2);
title('2nd Carrier Signal');

for i = 0 : 1000
	if (m(i + 1) == 0)
		w(i + 1) = c2(i + 1);
	else
		w(i + 1) = c1(i + 1);
	end
end
subplot(4, 1, 4);
plot(t, w);
title('FSK Signal');