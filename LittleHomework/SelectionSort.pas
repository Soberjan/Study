program SelectionSort;

const N = 6;
var
  a : array [0..N] of integer;
  i, j, max, t : integer;

begin

  Randomize();
  for i := 1 to N do
    a[i] := random (13);

  for i := 1 to N do
    writeln(a[i]);

  Readln();

  for i := 1 to N do
  begin
    min := i;
    for j := i + 1 to N do
      if a [j] < min then
        min := j;
    t := a[min];
    a[min] := a[i];
    a[i] := t;
  end;

end.

