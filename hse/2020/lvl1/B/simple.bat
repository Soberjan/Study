@echo off
set dst=tests
g++ --std=gnu++11 -O2 -Wl,--stack,67108864 %~n0.cpp -o %~n0.exe
for %%i in (%dst%\*.) do (%~n0.exe <%%i >%dst%\%%~ni.out
fc /A %dst%\%%~ni.out %dst%\%%~ni.a)
del %dst%\*.out %~n0.exe %~n0.tmp %~n0.o
pause
