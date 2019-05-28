function [z] = ands(x, y)
	if (x == 1 && y == 1)
		z = 1;
	else
		z = 0;
	end
end