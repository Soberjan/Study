@echo off
set dst=check
fpc.exe %~n0.lpr > %~n0.tmp
for %%i IN ( %dst%\*.a ) do (
%~n0.exe < %dst%\%%~ni > %dst%\%%~ni.out 
fc %%i %dst%\%%~ni.out
del %dst%\%%~ni.out                   
)                                                                                  
del %~n0.o %~n0.exe %~n0.tmp                                         
pause
