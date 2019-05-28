clc;
clear all;
close all;

x = input('Enter a bit (x): ');
y = input('Enter another bit (y): ');

fprintf('\nor(%d, %d) = %d\n', x, y, ors(x, y));
fprintf('\nand(%d, %d) = %d\n', x, y, ands(x, y));
fprintf('\nnot(x) = %d\n', nots(x));
fprintf('\nnot(y) = %d\n', nots(y));
fprintf('\nnor(%d, %d) = %d\n', x, y, nors(x, y));
fprintf('\nnand(%d, %d) = %d\n', x, y, nands(x, y));
fprintf('\nxor(%d, %d) = %d\n', x, y, xors(x, y));
fprintf('\nxnor(%d, %d) = %d\n', x, y, xnors(x, y));