fpc.exe tests_gen.lpr > %~n0.tmp
tests_gen.exe
del %~n0.o %~n0.exe %~n0.tmp
pause
