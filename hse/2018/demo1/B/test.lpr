program test;


const
  NLIM = 30;

var
  a: array[1..NLIM] of integer;
  i, j, n, k: integer;

  function simple(): integer;
  begin
  end;

  function optimal(): integer;
  var
    i, j, max, t, min, max2: integer;
  begin
    min := 0;
    max2 := 0;
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
    for i := k + 1 to n do
      if a[i] < min then
        min := a[i];
    for i := k + 1 to n do
      if a[i] > max2 then
        max2 := i;
    exit(max2 - max);
  end;

begin

  for i := 1 to 10000 do
  begin
    k := random(10) + 1;
    n := NLIM - random(NLIM div 2);
    for j := 1 to n do
      a[j] := random(30) + 1;
    if simple() <> optimal() then
      writeln('error!');

  end;
  writeln('done!');
  Readln();
end.




