clc;
clear all;
close all;

fprintf('Enter m:\n');
for i = 1 : 1 : 4
	fprintf('Bit %d: ', i);
	m(i) = input('');
end

fprintf('\nEnter q:\n');
for i = 1 : 1 : 4
	fprintf('Bit %d: ', i);
	q(i) = input('');
end

temp = q;

a = [0 0 0 0];
c = 0;

for i = 4 : -1 : 1
	if (q(4) == 1)
		[a, c] = add_num(c, a, m);
	end
	[c, a, q] = shift_right(c, a, q);
end

ans = [a, q];

fprintf('\nm = ');
fprintf('%d ', m);
fprintf('\nq = ');
fprintf('%d ', temp);
fprintf('\na = ');
fprintf('%d ', a);
fprintf('\nq = ');
fprintf('%d ', q);
fprintf('\nans (m * q) = ');
fprintf('%d ', ans);
fprintf('\n');

figure('name', 'Multiplication');
subplot(3, 2, 1);
stem(m);
axis([0 5 -0.5 1.5]);
title('m');

subplot(3, 2, 2);
stem(temp);
axis([0 5 -0.5 1.5]);
title('q');

subplot(3, 2, 3);
stem(a);
axis([0 5 -0.5 1.5]);
title('a');

subplot(3, 2, 4);
stem(q);
axis([0 5 -0.5 1.5]);
title('q');

subplot(3, 2, [5 6]);
stem(ans);
axis([0 9 -0.5 1.5]);
title('ans');