clc
clear all;
close all;
 
fprintf('Enter m:\n');
m(0) = 0;
for i = 2 : 1 : 5
	fprintf('Bit %d: ', i - 1);
	m(i) = input('');
end

fprintf('\nEnter q:\n');
for i = 1 : 1 : 4
	fprintf('Bit %d: ', i);
	q(i) = input('');
end

temp = q;

for i = 4 : -1 : 1
	[a, q] = shift_left(a, q);
	
	b = 0;
	[s, b] = sub_num(b, a, m);
	[s, 0] = sub_num(0, a, m);
	
	if (a(1) == 1)
		q(4) = 0;
		[s, 0] = add_num(0, a, m);
	else
		q(4) = 1;
	end
end

fprintf('\nm = ');
fprintf('%d ', m);
fprintf('\nq = ');
fprintf('%d ', temp);
fprintf('\na = ');
fprintf('%d ', a);
fprintf('\nq = ');
fprintf('%d ', q);
fprintf('\n');

figure('name', 'Division');

subplot(2, 2, 1);
stem(m);
axis([0 6 -0.5 1.5]);
title('m');

subplot(2, 2, 2);
stem(temp);
axis([0 6 -0.5 1.5]);
title('q');

subplot(2, 2, 3);
stem(a);
axis([0 6 -0.5 1.5]);
title('a');

subplot(2, 2, 4);
stem(q);
axis([0 6 -0.5 1.5]);
title('q');