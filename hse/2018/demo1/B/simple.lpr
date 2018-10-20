program simple;

uses
  Math;

const
  NLIM = 30;

var
  a: array[1..NLIM] of longint;
  n, k, i, j, t, maxx: longint;

  function noncomf(c: integer): longint;
  var
    i, maxt, mint: longint;
  begin
    maxt := -273;
    mint := 10000000;
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

  function popcount(n: integer): longint;
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
        if (noncomf(c) < minnoncomf) then
          minnoncomf := min(minnoncomf, noncomf(c));

    exit(minnoncomf);
  end;

begin
  //assign(input, 'tests\03');
  //reset(input);

  Readln(n, k);
  for i := 1 to n do
    Read(a[i]);
  for i := 1 to n - 1 do
  begin
    maxx := i;
    for j := i to n do
      if (a[j] > a[maxx]) then
        maxx := j;
    t := a[maxx];
    a[maxx] := a[i];
    a[i] := t;
  end;
  Writeln(simple());
end.

