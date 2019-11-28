@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (0, 1, 9) do %~n0.exe %%i 1000 1000 > tests/1%%i 
for /l %%i in (0, 1, 9) do %~n0.exe %%i 200000 200000 > tests/2%%i 
pause
