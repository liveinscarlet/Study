clc;
clear;

SAMPLE_RATE_Hz = 48000;

% 1) —оздаЄм синхро-сигнал ZC:
% 1.1) —оздание символов ZC:
ZC_count = 127; % isprime(ZC_count) ћ≈Ќя“№
ZC_root  =   126; %%ћ≈Ќя“№

mas_ZC_symbols = zeros(ZC_count, 1);
for i = 1 : 1 : ZC_count
   mas_ZC_symbols(i) = exp(-1i*pi *ZC_root *(i-1)*i /ZC_count);
end % i

% 1.2) ѕолосова€ модул€ци€:
sps = 16; % samples per symbol ћ≈Ќя“№

mas_Tx_etalon_IQ = sps * upsample(mas_ZC_symbols, sps);
mas_Tx_etalon_IQ = conv(mas_Tx_etalon_IQ, fir_rcos(sps, 3, 0.25), 'same');

my_oscillogram(mas_Tx_etalon_IQ, SAMPLE_RATE_Hz);
my_spectr(mas_Tx_etalon_IQ, SAMPLE_RATE_Hz, 32);

% 2) »скажени€ в радиоканале:

delta_T_ms = 5;
SNR_dB = 10; %%ћ≈Ќя“№

delta_T = round(SAMPLE_RATE_Hz * delta_T_ms / 1000);
mas_Tx_IQ = [zeros(delta_T, 1); mas_Tx_etalon_IQ; zeros(delta_T, 1)];

nse_sigma = 10^(-SNR_dB/20);
mas_Rx_IQ = add_AWGN(mas_Tx_IQ, nse_sigma);

% 3) ‘ункци€ неопределЄнности:

delta_F_Hz = 80; % √ц
NF = 81;

[matr_UF, ...
 mas_t, mas_f, matr_h, ...
 matr_NseSigma, matr_SNR_dB] = my_Uncertainty_Function(mas_Rx_IQ, mas_Tx_etalon_IQ, ...
                                                       delta_F_Hz, NF, ...
                                                       SAMPLE_RATE_Hz);
figure();
imagesc(mas_f, mas_t, matr_UF);
map = (1 : -0.01 : 0).^1.';
colormap([map map map]);
grid on;
xlabel('\deltaf, √ц');
ylabel('\deltat, мс');
title('‘ункци€ неопределЄнности');

figure();
surf(mas_f, mas_t, matr_UF, 'LineStyle', 'none');
map = (1 : -0.01 : 0).^1.';
colormap([map map map]);
xlabel('\deltaf, √ц');
ylabel('\deltat, мс');
title('‘ункци€ неопределЄнности');

dF1_Hz = -50;
dF2_Hz =   0;
dF3_Hz =  70;
[m, f1] = min( abs(mas_f - dF1_Hz) );
[m, f2] = min( abs(mas_f - dF2_Hz) );
[m, f3] = min( abs(mas_f - dF3_Hz) );
% figure();
% hold all;
% plot(mas_t, matr_UF(:, f1), 'DisplayName', ['dF ' num2str(dF1_Hz) ' √ц']);
% plot(mas_t, matr_UF(:, f2), 'DisplayName', ['dF ' num2str(dF2_Hz) ' √ц']);
% plot(mas_t, matr_UF(:, f3), 'DisplayName', ['dF ' num2str(dF3_Hz) ' √ц']);
% hold off;
% legend show;
% grid on;
% xlabel('\deltat, мс');
% title('ќтклик согл. фильтра');

% figure();
% imagesc(mas_f, mas_t, matr_SNR_dB);
% grid on;
% xlabel('\deltaf, √ц');
% ylabel('\deltat, мс');
% title('');
% title('ќценка SNR по функции неопределЄнности');
