program test;

uses
  Math;

const
  NLIM = 30;

var
  a: array[1..NLIM] of longint;
  i, j, n, k, simple_res, optimal_res: longint;

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
    for c := 1 to maxc - 2 do
      if popcount(c) = n - k then
        minnoncomf := min(minnoncomf, noncomf(c));
    exit(minnoncomf);
  end;

  procedure SortArray();
  var
    i, j, max, t: longint;
  begin
    max := 0;
    t := 0;
    for i := 1 to n do
    begin
      max := i;
      for j := i + 1 to n do
        if a[j] > a[max] then
          max := j;
      t := a[max];
      a[max] := a[i];
      a[i] := t;
    end;
  end;

  function FindNonComf(kh: longint): longint;
  var
    i1, i2, t, noncomf1, noncomf2, noncomf3, noncomf4, ans: longint;
  begin
    i1 := 1;
    i2 := n;
    while kh > 0 do
    begin
      if a[i1] <> a[i2] then
      begin
        if a[i1 + 1] - a[i2] < a[i1] - a[i2 - 1] then
          i1 += 1
        else
          i2 += 1;
      end;
      if (a[i1] = a[i + 1]) or (a[i2] = a[i2 + 1]) then
      begin
        t := i1;
        i1 += kh;
        noncomf2 := a[i1] - a[i2];
        i1 := t;

        t := i2;
        i2 -= kh;
        noncomf3 := a[i1] - a[i2];
        i2 := t;

        noncomf4 := FindNonComf(kh - 1);
      end;
      kh -= 1;
    end;
    noncomf1 := a[i1] - a[i2];
    if (noncomf1 > 0) and (noncomf2 > 0) and (noncomf3 > 0) then
    begin
    ans := min(noncomf1, noncomf2);
    ans := min(ans, noncomf3);
    ans := min(ans, noncomf4);
    end;
    exit(ans);
  end;

  function optimal(): longint;
  var
    res: longint;
  begin
    if (n - k <= 1) then
      exit(0);
    //SortArray();  раскоммитить после переноса в optimal
    res := FindNonComf(k);

    exit(res);

  end;

begin
  for i := 1 to 10000 do
  begin
    k := random(3) + 1;
    n := random(10);
    for j := 1 to n do
      a[j] := random(30) - 15;

    SortArray();

    simple_res := simple();
    optimal_res := optimal();
    if simple_res <> optimal_res then
    begin
      writeln('error!');
      optimal();
    end;
  end;
  writeln('done!');
  Readln();
end.



