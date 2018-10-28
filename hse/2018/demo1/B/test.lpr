program test;

uses
  Math;

const
  NLIM = 30;

var
  a: array[1..NLIM] of longint;
  i, j, n, k: longint;

  function noncomf(c: integer): integer;
  var
    i, maxt, mint: integer;
  begin
    maxt := -273;
    mint := 1000000000;
    for i := 1 to n do
    begin
      if c mod 2 = 1 then
      begin
        maxt := max(maxt, a[i]);
        mint := min(mint, a[i]);
      end;
      c := c div 2;
    end;
    exit(maxt - mint);
  end;

  function popcount(n: integer): integer;
  begin
    popcount := 0;
    while (n > 0) do
    begin
      popcount += n mod 2;
      n := n div 2;
    end;
  end;

  function simple(): longint;
  var
    c, maxc, minnoncomf: longint;
  begin
    if (n - k <= 1) then
      exit(0);
    maxc := (1 shl n) - 1;
    minnoncomf := noncomf(maxc);
    for c := 1 to maxc - 1 do
      if popcount(c) = n - k then
        minnoncomf := min(minnoncomf, noncomf(c));
    exit(minnoncomf);
  end;

  procedure sort(l, r: integer);
  var
    i, j, x, y: integer;
  begin
    i := l;
    j := r;
    x := a[l + random(r - l + 1)];
    repeat
      while a[i] < x do
        i := i + 1;
      while x < a[j] do
        j := j - 1;
      if i <= j then
      begin
        if a[i] > a[j] then
        begin
          y := a[i];
          a[i] := a[j];
          a[j] := y;
        end;
        i := i + 1;
        j := j - 1;
      end;
    until i >= j;
    if l < j then
      sort(l, j);
    if i < r then
      sort(i, r);
  end;

  function optimal(): longint;
  var
    i1, i2, noncomf: longint;
  begin
    if (n - k <= 1) then
      exit(0);
    //SortArray();
    i2 := n - k - 1;
    noncomf := a[n] - a[1];
    for i1 := 1 to k do
    begin
      i2 += 1;
      noncomf := min(noncomf, a[i2] - a[i1]);
    end;
    noncomf := min(noncomf, a[n] - a[k + 1]);
    exit(noncomf);
  end;

begin
  for i := 1 to 100000 do
  begin
    n := random(10);
    k := random(n) + 1;
    for j := 1 to n do
      a[j] := random(30) - 15;

    sort(1, n);

    if simple() <> optimal() then
    begin
      writeln('error!');
    end;
  end;
  writeln('done!');
  Readln();
end.



