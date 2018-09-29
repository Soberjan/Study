program simple;

const
  NLIM = 1000;

var
  a: array [1..NLIM] of integer;
  r, i, j, n: integer;

begin
  Readln(n);
  for i := 1 to n do
    Readln(a[i]);

  r := 0;
  for i := 1 to N - 1 do
    for j := i + 1 to N do
      if (r < a[i] * a[j]) and (a[i] * a[j] mod 14 = 0) then
        r := a[i] * a[j];

  Writeln(r);
end.

