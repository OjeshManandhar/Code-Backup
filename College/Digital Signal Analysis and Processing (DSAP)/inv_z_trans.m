clc
clear all
close all

z = [0.501637231965511 + 1.626490860044917i;0.501637231965511 - 1.626490860044917i;-0.910358245524393 + 0.443759807336589i;-0.910358245524393 - 0.443759807336589i;0.408721013558882 + 0.636435095037832i;0.408721013558882 - 0.636435095037832i];
p = [0.789989739502178 + 0.767000661149833i;0.789989739502178 - 0.767000661149833i;0.020370130928407 + 1.222264545170583i;0.020370130928407 - 1.222264545170583i;-1.010359870430584 + 0.288279666199223i;-1.010359870430584 - 0.288279666199223i];
k= 1;

[num, den] = zp2tf(z, p, k);

zplane(num, den);