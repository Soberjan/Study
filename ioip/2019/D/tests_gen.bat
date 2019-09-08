@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (1, 1, 9) do %~n0.exe %%i 10 10 2 > tests/0%%i
pause
