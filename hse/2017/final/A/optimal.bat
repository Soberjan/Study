@echo off
fpc.exe %~n0.lpr > %~n0.tmp
for %%i IN ( check\*.a ) do (
%~n0.exe < check\%%~ni > check\%%~ni.out 
fc %%i check\%%~ni.out
del check\%%~ni.out                         
)                                                                                  
del %~n0.o %~n0.exe %~n0.tmp                                         
pause
