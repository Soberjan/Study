@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (0, 1, 2) do %~n0.exe %%i 500 200 > tests/1%%i 
for /l %%i in (0, 1, 2) do %~n0.exe %%i 10000 10 > tests/2%%i 
for /l %%i in (0, 1, 2) do %~n0.exe %%i 100000 1 > tests/3%%i 
for /l %%i in (0, 1, 2) do %~n0.exe %%i 200000 1 > tests/4%%i 

pause
