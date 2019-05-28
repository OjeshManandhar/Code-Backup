clc;
clear all;
close all;

fprintf('Enter the first sequence (x):\n');
for i = 1 : 1 : 4
    fprintf('Bit %d: ', i);
	x(i) = input('');
end

fprintf('\nEnter the second sequence (y):\n');
for i = 1 : 1 : 4
    fprintf('Bit %d: ', i);
	y(i) = input('');
end

b = input('\nEnter borrow input: ');

for i = 4 : -1 : 1
    d(i) = xor(xor(x(i), y(i)), b);
    b = or(and(not(x(i)), xor(y(i), b)), and(y(i), b));
end

ans = [b, d];

fprintf('\nx = ');
fprintf('%d ', x);
fprintf('\ny = ');
fprintf('%d ', y);
fprintf('\nb = %d', b);
fprintf('\nd = ');
fprintf('%d ', d);
fprintf('\nans (x - y) = ');
fprintf('%d ', ans);
fprintf('\n');

figure('name', 'Subtraction');
subplot(3, 2, 1);
stem(x);
axis([0 5 -0.5 1.5]);
title('x');

subplot(3, 2, 2);
stem(y);
axis([0 5 -0.5 1.5]);
title('y');

subplot(3, 2, 3);
stem(b);
axis([0 5 -0.5 1.5]);
title('borrow');

subplot(3, 2, 4);
stem(d);
axis([0 5 -0.5 1.5]);
title('difference');

subplot(3, 2, [5 6]);
stem(ans);
axis([0 6 -0.5 1.5]);
title('ans');