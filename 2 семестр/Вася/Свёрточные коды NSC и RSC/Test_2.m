
clc;
clear;

% ToDo:
% 1) ѕользу€сь справкой MatLab, разобратьс€ в структуре кодеров (нарисовать их в виде схемы со сдвиговыми регистрами)
% 2) —равнить длины "импульсной характеристики" NSC-кодеров и RSC-кодеров с 
%                                                 coder_constraint = 3
%                                                 coder_constraint = 7
%                                                 coder_constraint = 11
% ќбъ€снить, почему длины разные. 
% 3) —делать выводы об отличии NSC от RSC.

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
title('Ѕиты на входе');
subplot(3, 1, 2);
stem(mas_bits_NSC_encoded);
title('Ѕиты на выходе NSC');
subplot(3, 1, 3);
stem(mas_bits_RSC_encoded);
title('Ѕиты на выходе RSC');


