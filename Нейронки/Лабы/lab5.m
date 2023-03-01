clear; close all; clc;
%% Задание исходной функции

x = linspace(-2, 3, 1000);
y = sin(x.^2 - x);
plot(x, y)
grid on; grid minor;
%% Обучение нейросети

grid on;
p = x([1 : 5: 1000]); 
t = y([1 : 5: 1000]);

net1 = newff(minmax(p), [7 1], {'tansig' 'purelin'});

net1.trainParam.epochs = 500;
net1 = train(net1, p, t);

y1 = sim(net1, p);
plot(p, y1, 'g', p, t, 'r');
grid on; 
grid minor;