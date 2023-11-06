clear; clc; close all;
%% Basic constants

freq = 900 * 10 ^ (6);
dist = linspace(0, 5000, 1000);
level = 2;       %dBm
Ku = 4;          %dB
P = 100;         %Вт
c = 3 * 10 ^ (8);
lambda = c / freq;

%% Free space losses


%% O-H model losses
h1 = 50;
h2 = 5;


%% K-B model losses
street_width = 10;
dist_to_roof = 10;
roof_high = 55;

%% Ehle equation

%%
%Отчет состоит из задания по расчету потерь по 4 формулам и рассчитать
%дальность "двухлучевой 900 мгц 2 мбит/с по боковому лепестку для 8 элементной антенной решетки"
%Сравнить ЦАР и обычную решетку, в одном случае 100 Вт, в одном 4 дБ
%Переводы чувствительности и потерь в одни величины
%% For linear antenna array
N = 8;
feel = -93;       %dBm