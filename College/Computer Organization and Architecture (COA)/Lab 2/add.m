clc;
clear all;
close all;

fprintf('Enter the first sequence (a):\n');
for i = 1 : 1 : 4
    fprintf('Bit %d: ', i);
	a(i) = input('');
end

fprintf('\nEnter the second sequence (b):\n');
for i = 1 : 1 : 4
    fprintf('Bit %d: ', i);
	b(i) = input('');
end

c = input('\nEnter carry in: ');

for i = 4 : -1 : 1
	s(i) = xor(a(i), xor(b(i), c));
	c = or(and(a(i), b(i)), and(xor(a(i), b(i)), c));
end

ans = [c, s];

fprintf('\na = ');
fprintf('%d ', a);
fprintf('\nb = ');
fprintf('%d ', b);
fprintf('\nc = %d', c);
fprintf('\ns = ');
fprintf('%d ', s);
fprintf('\nans (a + b)= ');
fprintf('%d ', ans);
fprintf('\n');

figure('name', 'Addition');
subplot(3, 2, 1);
stem(a);
axis([0 5 -0.5 1.5]);
title('a');

subplot(3, 2, 2);
stem(b);
axis([0 5 -0.5 1.5]);
title('b');

subplot(3, 2, 3);
stem(c);
axis([0 5 -0.5 1.5]);
title('carry');

subplot(3, 2, 4);
stem(s);
axis([0 5 -0.5 1.5]);
title('sum');

subplot(3, 2, [5 6]);
stem(ans);
axis([0 6 -0.5 1.5]);
title('ans');