
clc;
clear;

% ToDo:
% 1) ��������� �������� MatLab, ����������� � ��������� ������� (���������� �� � ���� ����� �� ���������� ����������)
% 2) ���������� �� ����� ������� ����������� BER �� SNR ��� ������� � 
%                                                 coder_constraint = 3
%                                                 coder_constraint = 7
%                                                 coder_constraint = 11
% 3) ������� ������ �� ������������� �������, �������� �� ������������ � �������������� �������.

addpath('src');

coder_constraint = 3;

% Nonrecursive Systematic Convolutional Coder:
trellis_NSC = poly2trellis(coder_constraint, [dec2oct(2^(coder_constraint-1)) dec2oct(2^coder_constraint-3)]);
obj_ConvEnc_NSC = comm.ConvolutionalEncoder(trellis_NSC, 'TerminationMethod', 'Truncated');

N_info_bits = 200000;
mas_Tx_info_bits = randi([0 1], N_info_bits, 1);

mas_Tx_channel_bits = obj_ConvEnc_NSC(mas_Tx_info_bits);

% ���������� BPSK ���������:
Amp = 1;
mas_Tx_IQ = Amp * (2*mas_Tx_channel_bits - 1);

mas_SNR_dB = -6 : 0.5 : 6;
mas_BER = zeros(length(mas_SNR_dB), 1);

overall_decoding_time = 0; % � ��������

for n = 1 : 1 : length(mas_SNR_dB)
   
   % ���:
   nse_sigma = Amp * 10^(-mas_SNR_dB(n)/20);
   mas_Rx_IQ = add_AWGN(mas_Tx_IQ, nse_sigma);

   % ���������� BPSK �����������:
   mas_Rx_channel_bits = double(real(mas_Rx_IQ) > 0);
   
   % �������:
   obj_ConvDecViterbi_NSC = comm.ViterbiDecoder(trellis_NSC,'InputFormat','Hard', 'TerminationMethod', 'Truncated');
   tic;
   mas_Rx_info_bits = obj_ConvDecViterbi_NSC(mas_Rx_channel_bits);
   overall_decoding_time = overall_decoding_time + toc;
   reset(obj_ConvDecViterbi_NSC);
   
   mas_BER(n) = count_ber(mas_Rx_info_bits, mas_Tx_info_bits) + 1e-10;
end % n
average_decoding_time = overall_decoding_time / length(mas_SNR_dB) / N_info_bits * 10^9; % [���������� �� 1 ���]


figure();
plot(mas_SNR_dB, mas_BER,'LineWidth',1,'Color',[0 0 0]);
set(gca,'XGrid','on','YGrid','on','YMinorTick','on','YScale','log');
xlabel('SNR, dB');
ylabel('BER');
ylim([1e-5 1]);
title(sprintf('coder constraint = %d (%5.1f ��/���)', coder_constraint, average_decoding_time));
