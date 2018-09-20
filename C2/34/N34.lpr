program N34;

const
  N = 6;
var
  a: array [1..N] of integer;
  i, j, x, y: integer;

begin
  x := -255;

  for i := 1 to N do
    readln(a[i]);

  for i := 1 to N do
  begin
    for j := i + 1 to N do
    begin
      if abs(a[i] - a[j]) > x then
        x := a[i] - a[j];
    end;
  end;

  writeln(x);
  Readln();

end.
