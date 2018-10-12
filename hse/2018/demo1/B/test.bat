fpc test.lpr > %~n0.tmp
test.exe
del %~n0.o %~n0.exe %~n0.tmp
pause