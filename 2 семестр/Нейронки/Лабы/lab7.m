clear all; close all; clc;

x = linspace(1, 10, 100);
y = exp(x)./x.^3;

plot(x, y)
grid on;
