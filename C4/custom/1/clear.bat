for %%g in ( *.o ) do (
   del %%g
)
for %%g in ( *.exe ) do (
   del %%g
)
for %%g in ( *.lps ) do (
   del %%g
)
for %%g in ( *.lps ) do (
   del %%g
)
for %%g in (tests\*.out ) do (
   del %%g
)



del "Backup" /q
@RD /S /Q "Backup"
@RD /S /Q "lib"