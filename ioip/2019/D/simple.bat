@echo off
set dst=check
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for %%i in (%dst%\0*.) do (%~n0.exe <%%i >%dst%\%%~ni.out
fc /A %dst%\%%~ni.out %dst%\%%~ni.a)
del %dst%\*.out %~n0.exe %~n0.tmp %~n0.o
pause
