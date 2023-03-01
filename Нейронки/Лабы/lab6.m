%% Формирование исходной поверхности

clear; close; clc;

x = linspace(0,5,100);
y = linspace(1,5,100);
[x, y] = meshgrid(x, y);
z = (x + y).^(1/3);
mesh(x, y, z)
grid on;
%% Обучение нейронки
XX = x(1:end);
YY = y(1:end);
ZZ = z(1:end);
p = [XX; YY];
t = ZZ;

net2 = newrbe(p, t); % Нейронка с радиальными базисными элементами
ynet = sim(net2, p); % Не требует отдельного обучения
%% Тестировочная поверхность
x1 = linspace(0,5,200);
y1 = linspace(1,5,200);
[x1, y1] = meshgrid(x1, y1);
z1 = (x1 + y1).^(1/3);

XX1 = x1(1:end);
YY1 = y1(1:end);
ZZ1 = z1(1:end);
ptest = [XX1; YY1];
ttest = ZZ1;
yt = sim(net2, ptest);
YT = reshape(yt, size(z1));

figure
subplot(1,2,1);
mesh(x1, y1, z1);
grid on
subplot(1,2,2);
mesh(x1, y1, YT);
grid on


