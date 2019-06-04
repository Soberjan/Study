@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /l %%i in (0, 1, 9) do %~n0.exe %%i > tests/1%%i                   
del %~n0.o %~n0.tmp 
pause
