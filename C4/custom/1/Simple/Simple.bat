Set S=simple.pas
ren "%S|*.bat" "*.exe"
S fpc
set /p temp="Write the number of tests you'd like to check"
For %%A in (tests) do fc .out .a
