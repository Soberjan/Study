program task33;

const
  N = 6;
var
  a: array [1..N] of integer;
  i, j, min, min2, s: integer;

begin

  s := 255;

  for i := 1 to N do
    readln(a[i]);

  for i := 1 to N do
  begin
      for j := i + 1 to N do
      begin
        if (abs(a[i] - a[j]) < s) then
          min := i;
          min2 := j;
      end;
  end;
  writeln(min);
  writeln(min2);
  readln();

end.

