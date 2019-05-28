function [d, b] = sub_num(b, x, y)
    for i = 5 : -1: 1
		d(i) = xor(xor(x(i), y(i)), b);
		b = or(and(not(x(i)), xor(y(i), b)), and(y(i), b));
    end
end