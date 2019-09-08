@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (3, 1, 9) do %~n0.exe %%i 12 > tests/0%%i                   

pause
