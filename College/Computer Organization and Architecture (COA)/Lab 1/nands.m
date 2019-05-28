function [z] = nands(x, y)
	if (x == 1 && y == 1)
		z = 0;
	else
		z = 1;
	end
end