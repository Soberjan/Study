program optimal;

var
  a : array[1..100] of integer;
  i, n, k : integer;

function optimal(): integer;
  var
    i, j, max, t, min, max2: integer;
  begin
    max := 0;
    t := 0;
    if (n - k <= 1) then
      exit(0);
    if (k > 0) then
    begin
      for i := 1 to k do
      begin
        max := i;
        for j := i + 1 to N do
          if abs(A[j]) > abs(A[max]) then
            max := j;
        t := a[max];
        a[max] := a[i];
        a[i] := t;
      end;
    end;
    min := a[k + 1];
    max2 := a[k + 1];
    for i := k + 1 to n do
      if a[i] < min then
        min := a[i];
    for i := k + 1 to n do
      if a[i] > max2 then
        max2 := a[i];
    exit(max2 - min);
  end;

begin
  Read(n, k);
  for i := 1 to n do
    Read(a[i]);
  Writeln(optimal());

  Readln();

end.
