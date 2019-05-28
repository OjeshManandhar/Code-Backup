function [c, a, q] = shift_right(c, a, q)
	q(4) = q(3);
	q(3) = q(2);
	q(2) = q(1);
	q(1) = a(4);
	a(4) = a(3);
	a(3) = a(2);
	a(2) = a(1);
	a(1) = c;
end