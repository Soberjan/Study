rem @echo off
fpc.exe %~n0.lpr
rem > %~n0.tmp 
for %%i IN ( tests\*.a ) do (
%~n0.exe < tests\%%~ni > tests\%%~ni.out 
fc %%i tests\%%~ni.out                      
)                                                                                  
del %~n0.o %~n0.exe %~n0.tmp tests\*.out                       
pause
