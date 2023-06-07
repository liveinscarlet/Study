function [matr_UF mas_t mas_f matr_h matr_NseSigma matr_SNR_dB] = my_Uncertainty_Function(mas_Rx, mas_etalon, ...
                                                                                           delta_F_Hz, NF, ...
                                                                                           SAMPLE_RATE_Hz)
   assert( mod(length(mas_Rx) - length(mas_etalon), 2) == 0 );
   
   Len = length(mas_Rx);
   N = length(mas_etalon);
   E = mas_etalon' * mas_etalon;

   NT = Len - N;
   
   mas_t = (-NT/2 : 1 : NT/2).'/SAMPLE_RATE_Hz;
   mas_f = 2*delta_F_Hz/(NF-1)*(0:1:NF-1).' - delta_F_Hz;

   matr_UF = zeros(NT+1, NF); % t f
   matr_h = zeros(NT+1, NF); % t f
   matr_NseSigma = zeros(NT+1, NF); % t f
   matr_SNR_dB = zeros(NT+1, NF); % t f

   for i_freq = 1 : 1 : NF
      sin_mas = exp(2i*pi* (0:1:Len-1) *mas_f(i_freq) /SAMPLE_RATE_Hz).';
      mas_Rx_shifted = mas_Rx .* sin_mas;

      for i_tau = 1 : 1 : NT+1
         rcv_mas = mas_Rx_shifted(i_tau:(i_tau+N-1));

         R = mas_etalon' * rcv_mas;
         Y = rcv_mas' * rcv_mas;

         alpha = R *R' /Y /E;
         h = R / E;
         NseDispersia = Y/N * (1 - alpha);
         SNR = N/E * alpha / (1 - alpha);
               
         matr_UF(i_tau, i_freq) = sqrt(abs(alpha));
         matr_h(i_tau, i_freq) = h;
         matr_NseSigma(i_tau, i_freq) = sqrt(NseDispersia);  
         matr_SNR_dB(i_tau, i_freq) = 10 * log10( SNR );
      end % i_tau
   end % i_freq

end % function

