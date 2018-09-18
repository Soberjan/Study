program N39;

const
  N = 6;
var
  a: array [1..N] of integer;
  i, j, k, imax, kmax: integer;

begin

  for i := 1 to N do
    Readln(a[i]);

  for i := 1 to N do
  begin
    for j := 1 to a[i] do
      if a[i] mod j = 0 then
        k := k + 1;
    if k > kmax then
    begin
      kmax := k;
      imax := i;
      k := 0;
    end
    else then
      k := 0;
  end;

  Writeln(imax);
  Readln();

end.
