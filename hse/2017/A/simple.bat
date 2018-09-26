fpc.exe %~n0.lpr > temporaryfile.t
for %%g IN ( tests\*.a ) do (
%~n0.exe < tests\%%~ng > tests\%%~ng.out 
fc %%g tests\%%~ng.out
del tests\%%~ng.out                         
)                                                                                  
del *.o *.exe *.lps temporaryfile.t
@RD /S /Q "Backup"
@RD /S /Q "lib"                                        
pause
