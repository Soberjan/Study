@echo off
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
%~n0.exe
del %~n0.o %~n0.exe %~n0.tmp %~n0.depend %~n0.layout
pause