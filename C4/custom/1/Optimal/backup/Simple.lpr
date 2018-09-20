program Simple;

const
  Nlim = 1000;

var
  a: array [1..Nlim] of integer;
  Rmax, R, i, j, N: integer;

begin
  Readln(N);
  for i := 1 to N do
    Readln(a[i]);

  Rmax := 0;
  for i := 1 to N - 1 do
    for j := i + 1 to N do
    begin
      R := a[i] * a[j];
      if (Rmax < R) and (R mod 14 = 0) then
        Rmax := R;
    end;

  Writeln(Rmax);

end.

