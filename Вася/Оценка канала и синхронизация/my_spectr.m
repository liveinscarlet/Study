function [figure_id, mas_spectr] = my_spectr(mas_IQ, SAMPLE_RATE_Hz, N_repeats)

   if (nargin <= 2)
      N_repeats = 1;
   end % if

   % ќпредел€ем размерность IQ_mas:
   dims = size(mas_IQ);
   if (length(dims) == 1)
      dims = [dims 1];
   end
   if (dims(1) <= dims(2))
      fprintf('ERROR in my_spectr()! mas_IQ N_rows must be less than N_cols! 1 col is 1 graph!\n');
   end % if
   assert (dims(1) > dims(2));
  
   mas_IQ_long = [];
   for n = 1 : 1 : N_repeats
      mas_IQ_long = [mas_IQ_long; exp(2i*pi*randi(512,1,1)/512)* mas_IQ];
   end% n
   
   % ќпредел€ем, сколько точек рисовать
   dims = size(mas_IQ_long);
   if (2^nextpow2(dims(1)) == dims(1))
      n_fft = dims(1);
   else
      n_fft = 2^(nextpow2(dims(1))-1);
   end

   % –асчЄт:
   w = window(@blackmanharris, n_fft);
   
   mas_spectr = [];
   for n = 1 : 1 : dims(2)
%      y_mas = pwelch(IQ_mas(1:n_fft, n), n_fft);
%      y_mas = 10*log10(fftshift(abs(y_mas)));
      
      y_mas = fft(mas_IQ_long(1:n_fft, n) .* w, n_fft);
      y_mas = 20*log10(fftshift(abs(y_mas)));

      mas_spectr = [mas_spectr, y_mas];
   end % for n
   
   % ƒл€ нормировки спектра:
   max_val = max(mas_spectr(:));
   
   % –исование:
   x_mas = (-n_fft/2 : 1 : n_fft/2-1)'/n_fft*SAMPLE_RATE_Hz/1000;
   figure_id = figure();
   hold all;
   for n = 1 : 1 : dims(2)
      plot(x_mas, mas_spectr(:,n) - max_val);
   end % for n
   hold off;
   title('—пектр');
   grid on;
   xlabel('\deltaf, к√ц');
   ylabel('P_н_о_р_м, дЅ');  
end


