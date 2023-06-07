clc; close all; clear;
%% Объявление констант

bps = 4;                            % Количество бит на символ
N = 1000;                           % Длина сообщения
SAMPLE_RATE_Hz = 96000;             % Частота дискретизации
% rng(101);                           % seed для генератора случайных чисел
bandwidth = 8 * 10 ^ 3;             % Ширина основного лепестка
T = 1 / bandwidth;                  % Частота следования симоволов синхропосылки
interpole_order = 12;               % Интерполяция сигнала, зависит от частоты дискретизации и ширины сигнала
delta_freq = 12 * 10 ^ 3;           % Частотная расстройка
lim = - 70;                         % Ограничение на уровень боковых лепестков, дБ
%% Формирование символов синхропосылки

Mseq_M = 8;    % показатель степени M-seq
Mseq_type = 1;

mas_Mseq_symbols = 0.707 * mseq(2, Mseq_M, 0, Mseq_type) + 0.707i * mseq(2, Mseq_M, 0, Mseq_type+1);
norm_m = max(abs(mas_Mseq_symbols));
mas_Mseq_symbols_norm = mas_Mseq_symbols / norm_m; % Нормировка
sps = 16; % samples per symbol

mas_Tx_etalon_IQ = sps * upsample(mas_Mseq_symbols_norm, sps);
mas_Tx_etalon_IQ = conv(mas_Tx_etalon_IQ, fir_rcos(sps, 3, 0.25), 'same');

% Картинки
my_oscillogram(mas_Tx_etalon_IQ, SAMPLE_RATE_Hz);
my_spectr(mas_Tx_etalon_IQ, SAMPLE_RATE_Hz, 32);
%% Генерация самого сообщения

msg = randi([0 1], N * bps, 1);     % Формируем случайные символы
msgM = reshape(msg, bps, []).';     % Меняем форму массива, чтобы символы формировались корректно
msgS = bi2de(msgM);                 % Перевод из двоичной системы в десятиричную, можно использовать как индексы создвездия
clx_msg = qammod(msgS, 16);         % Формирование комплексных символов созвездия
norm = max(abs(clx_msg));
clx_msg_norm = clx_msg / norm;      % Нормировка

figure() % График сигнального созвездия
scatterplot(clx_msg_norm)           
title ('Сигнальное созвездие');
grid on; grid minor;
%% Формирование сигнала

I_comp = sin(bandwidth / 2);
Q_comp = cos(bandwidth / 2);

for i = 1:N
    signal = real(clx_msg_norm) * I_comp + imag(clx_msg_norm) * Q_comp;
end

signal = spline(1:N, signal, 1:0.05:N);
signal_2 = fir_rcos(interpole_order,signal,0.25);

figure()            %Осцилограмма сигнала
plot(signal)
hold on
plot(signal_2)
xlim([0 500])
grid on; 
grid minor;
xlabel('Отсчеты')
ylabel('Амплитуда сигнала')

out = upsample(clx_msg_norm, 12);   % Заполнение массива нулями между информационными символами

% figure()
% plot(abs(out))
% xlim([0 500])