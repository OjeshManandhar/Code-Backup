function [a, q] = shift_left(a, q)
	a(1) = a(2);
	a(2) = a(3);
	a(3) = a(4);
	a(4) = a(5);
	a(5) = q(1);
	q(1) = q(2);
	q(2) = q(3);
	q(3) = q(4);
	q(4) = 0;
end