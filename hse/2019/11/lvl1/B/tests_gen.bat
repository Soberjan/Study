@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (3, 1, 9) do %~n0.exe %%i 30 10 10 > tests/0%%i 
rem for /l %%i in (0, 1, 9) do %~n0.exe %%i 20 10 > tests/1%%i 
rem for /l %%i in (0, 1, 9) do %~n0.exe %%i 50 50 > tests/2%%i 
rem for /l %%i in (0, 1, 9) do %~n0.exe %%i 100 100 > tests/3%%i 
rem for /l %%i in (0, 1, 9) do %~n0.exe %%i 1000 100 > tests/4%%i 

pause
