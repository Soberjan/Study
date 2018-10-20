program test;
uses
  Math;

const
  NLIM = 30;

var
  a: array[1..NLIM] of longint;
  maxnum, t, i, j, h, n, k, simple_res, optimal_res: longint;

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

  function popcount (n: integer): integer;
  begin
    popcount := 0;
    while(n > 0) do
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

  function optimal(): integer;
  var
    i, i1, i2, j, max, t, kh, res: integer;
  begin
    max := 0;
    t := 0;
    kh := k;
    if (n - k <= 1) then
      exit(0);
    if (k > 0) then
    begin
      for i := 1 to k do
      begin
        max := i;
        for j := i + 1 to N do
          if a[j] > a[max] then
            max := j;
        t := a[max];
        a[max] := a[i];
        a[i] := t;
      end;
    end;

    i1 := 1;
    i2 := n;
    while kh >= 1 do
    begin
      kh -= 2;
      if a[i1 + 1] = a[i1] then
        i2 -= 2
      else
      begin
        i1 += 1;
        i2 -= 1;
      end;
    end;

    if kh = 1 then
      res := min(a[i1 + 1] - a[n - i2], a[i1] - a[i2 - 1]);
    if kh = 0 then
      res := a[i1] - a[i2];

    exit(res);


  end;

begin
  for i := 1 to 10000 do
  begin
    k := random(3) + 1;
    n := random(10);
    for j := 1 to n do
      a[j] := random(30) - 15;

    for j := 1 to n - 1 do
    begin
      maxnum := j;
      for h := j + 1 to n do
        if a[h] > a[maxnum] then
          maxnum := h;
      t := a[j];
      a[j] := a[maxnum];
      a[maxnum] := t;
    end;

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



