@echo off
set dst=check
g++ -O2 --std=gnu++11 -m32 -lm %~n0.cpp -o %~n0.exe
for /D %%j in (%dst%\*) do (
    for %%i in (%%j\*.) do (
        %~n0.exe <%%i >%%j\%%~ni.out 
        fc /A %%j\%%~ni.out %%j\%%~ni.a
    )
    del %%j\*.out
)
del %~n0.exe %~n0.tmp %~n0.o
pause
