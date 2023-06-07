
clc;
clear;

% ToDo:
% 1) ��������� �������� MatLab, ����������� � ��������� ������� (���������� �� � ���� ����� �� ���������� ����������)
% 2) �������� ����� "���������� ��������������" NSC-������� � RSC-������� � 
%                                                 coder_constraint = 3
%                                                 coder_constraint = 7
%                                                 coder_constraint = 11
% ���������, ������ ����� ������. 
% 3) ������� ������ �� ������� NSC �� RSC.

coder_constraint = 3;

% Nonrecursive Systematic Convolutional Coder:
trellis_NSC = poly2trellis(coder_constraint, dec2oct(2^coder_constraint-3));
obj_ConvEnc_NSC = comm.ConvolutionalEncoder(trellis_NSC);

% Recursive Systematic Convolutional Coder:
trellis_RSC = poly2trellis(coder_constraint, dec2oct(2^coder_constraint-3), dec2oct(2^coder_constraint-1));
obj_ConvEnc_RSC = comm.ConvolutionalEncoder(trellis_RSC);

N_info_bits = 100;
mas_bits_in = 0 * randi([0 1], N_info_bits, 1);
mas_bits_in(10) = 1;

mas_bits_NSC_encoded = obj_ConvEnc_NSC(mas_bits_in);
mas_bits_RSC_encoded = obj_ConvEnc_RSC(mas_bits_in);

figure();
subplot(3, 1, 1);
stem(mas_bits_in);
title('���� �� �����');
subplot(3, 1, 2);
stem(mas_bits_NSC_encoded);
title('���� �� ������ NSC');
subplot(3, 1, 3);
stem(mas_bits_RSC_encoded);
title('���� �� ������ RSC');


