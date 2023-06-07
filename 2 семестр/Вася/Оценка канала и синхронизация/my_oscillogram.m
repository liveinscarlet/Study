function no = my_oscillogram(IQ_mas, SAMPLE_RATE_Hz)

   % Определяем размерность IQ_mas:
   dims = size(IQ_mas);
   
   if (length(dims) == 1)
      dims = [dims 1];
   end

   assert (dims(1) > dims(2));
   
   len = dims(1);
   t_mas = (0:1:len-1)/SAMPLE_RATE_Hz*1000;
   figure();
   hold all;
   
   for n = 1 : 1 : dims(2)
      plot(t_mas, real(IQ_mas(:,n)), 'DisplayName', ['Re '  num2str(n)]);
      plot(t_mas, imag(IQ_mas(:,n)), 'DisplayName', ['Im '  num2str(n)]);
      plot(t_mas,  abs(IQ_mas(:,n)), 'DisplayName', ['Abs ' num2str(n)]);
   end % for n
   
   hold off;
   xlabel('t, мсек');
   title('Осциллограмма');
   grid on;

   no = 1;

end

