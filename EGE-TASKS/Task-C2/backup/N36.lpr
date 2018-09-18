program N36;

const
  N = 6;
var
  a: array [1..N] of integer;
  i, k, kMax: integer;

begin
  for i := 1 to N do
    Readln(a[i]);

  for i := 1 to N do
  begin
    if k := 0 then k := k+1;
    if a[i] = a[i + 1] then
      k := k + 1
    else
    begin
      if kMax < k then kMax := k;
      k := 0;
    end;

  end;

  Writeln(kmax);
  Readln();

end.
