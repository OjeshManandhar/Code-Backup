clc
clear all
close all

n = -10: 10;
y = sin(n);
stem(n ,y);
xlabel('n');
ylabel('y(n)');
title('sin');