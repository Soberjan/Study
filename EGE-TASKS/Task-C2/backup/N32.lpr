program N32;

const
  N = 6;

var
  a: array [1..N] of integer;
  i, j, min, min2, s: integer;

begin

  for i := 1 to N do
    Readln(a[i]);
  s := 255;

  for i := 1 to N do
  begin
    for j := i + 1 to N do
    begin
      if a[i] + a[j] < min then
        begin
          s := a[i] + a[j];
          min := i;
          min2 := j;
        end;
    end;
  end;

 Writeln(min, min2);
 Readln();

end.
