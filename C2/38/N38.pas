program N38;

const N = 30;
var a:array[1..N] of integer;
i, k, kMin: integer;

Begin

  for i := 1 to N do Readln(a[i]);

  for i := 1 to N do
  Begin
    if a[i]<0 then k := k+1
    else if k <> 0 then
    begin
      kMin := k;
      k := 0;
    end;
  end;

  Writeln(kMin);

  Readln();

End.


end.

