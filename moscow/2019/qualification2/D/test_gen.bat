@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (1, 1, 9) do %~n0.exe %%i 20 5 10 > tests/0%%i                   
for /l %%i in (0, 1, 9) do %~n0.exe %%i 50 15 100 > tests/1%%i                   
for /l %%i in (0, 1, 9) do %~n0.exe %%i 500 75 100 > tests/2%%i                   
del %~n0.o %~n0.tmp 
pause
