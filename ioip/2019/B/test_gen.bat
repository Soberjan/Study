@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (2, 1, 9) do %~n0.exe %%i 30 10 30 10 > tests\0%%i
for /l %%i in (1, 1, 9) do %~n0.exe %%i 80 50 20 30 > tests\1%%i
for /l %%i in (0, 1, 9) do %~n0.exe %%i 60 80 120 20 > tests\2%%i 
pause
