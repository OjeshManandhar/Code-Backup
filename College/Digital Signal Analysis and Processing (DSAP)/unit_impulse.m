clc
clear all
close all

x = -10 : 10;
n = length(x);

for (i = 1 : n)
    if x(i) == 0
        u(i) = 1;
    else
        u(i) = 0;
    end
end

stem(x, u);