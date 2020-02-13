clc
clear all
close all

n = -10 : 10;
c = input('c = ');
a = input('a = ');
y = c*exp(a*n);
stem(n ,y);