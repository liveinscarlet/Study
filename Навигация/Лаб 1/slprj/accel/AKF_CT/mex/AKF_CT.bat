@echo off
set MATLAB=C:\Program Files\MATLAB\R2022a
"%MATLAB%\bin\win64\gmake" -f AKF_CT.mk  OPTS="-DTID01EQ=0"
