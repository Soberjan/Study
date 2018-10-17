program simple;

uses
  Math;

const
  NLIM = 100;

var
  a: array[1..NLIM] of integer;
  n, k, i,simple_res: integer;

  function noncomf(c: integer): integer;
  var
    i, maxt, mint: integer;
  begin
    maxt := -273;
    mint := 1000000000;
    i := n;
    while c > 0 do
    begin
      if c mod 2 = 1 then
      begin
        maxt := max(maxt, a[i]);
        mint := min(mint, a[i]);
      end;
      c := c div 2;
      i -= 1;
    end;
    //for i := n downto 0 do
    //begin
    //  if c mod 2 = 1 then
    //  begin
    //    maxt := max(maxt, a[i]);
    //    mint := min(mint, a[i]);
    //  end;
    //  c := c div 2;
    //end;
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

  function simple(): integer;
  var
    c, maxc, minnoncomf: integer;
  begin
    maxc := (1 shl n) - 1;
    minnoncomf := noncomf(maxc);
    for c := 0 to maxc - 1 do
      if popcount(c) = n - k then
        minnoncomf := min(minnoncomf, noncomf(c));
    exit(minnoncomf);
  end;

begin
  assign(input, 'tests\00');
  reset(input);
  Readln(n, k);
  for i := 1 to n do
    Readln(a[i]);
  simple_res := simple();
  Writeln(simple_res);
end.

