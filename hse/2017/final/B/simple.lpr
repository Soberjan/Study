program simple;
var
  a, b: array[1..100000] of longint;
  max1, max2, max3, n, i, j, s: longint;

begin
  Readln(n);
  max1 := 0;
  max2 := 1;
  max3 := 0;
  s := 0;

  for i := 1 to n do
    Readln(a[i]);

  for i := 1 to n do
  begin
    if a[i] > max2 then
    begin
      max1 := max2;
      max2 := i;
      max3 := i + 1;
      for j := max1 to max2 do
        b[j] := a[max1] - a[j];
    end;

    if (a[i] < max2) and (a[i] > max3) then
    begin
      max3 := i;
      for j := max2 to max3 do
        b[j] := a[max3] - a[j];
    end;
  end;
  for i := 1 to n do
    s += b[i];

  Writeln(s);

end.

