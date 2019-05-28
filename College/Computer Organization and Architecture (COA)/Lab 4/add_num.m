function [s, c] = add_num(c, a, b)
    for i = 5 : -1: 1
        s(i) = xor(a(i), xor(b(i), c));
        c = or(and(a(i), b(i)), and(xor(a(i), b(i)), c));
    end
end