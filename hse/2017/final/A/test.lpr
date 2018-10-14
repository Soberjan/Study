program test;

uses
  Math;

const
  NLIM = 10;

var
  a: array[1..NLIM] of integer;
  i, j, n : integer;

  function simple(): integer;
  var
    r, i, j: integer;
  begin
    r := 0;
    for i := 1 to n - 1 do
    begin
      for j := i + 1 to n do
        if (a[i] * a[j] > r) and (a[i] * a[j] mod 14 = 0) then
          r := a[i] * a[j];
    end;
    exit(r);
  end;

  function optimal(): integer;
  var
    i, m2, m7, m14, maxa, maxb: integer;

  begin
    m2 := 0;
    m7 := 0;
    m14 := 0;
    maxa := 0;
    maxb := 0;

    for i := 1 to n do
    begin
      if (a[i] mod 14 = 0) and (a[i] > m14) then
        m14 := a[i];
      if (a[i] mod 7 = 0) and (a[i] > m7) and (a[i] mod 14 <> 0) then
        m7 := a[i];
      if (a[i] mod 2 = 0) and (a[i] > m2) and (a[i] mod 14 <> 0) then
        m2 := a[i];
      if (a[i] >= maxa) then
      begin
        maxb := maxa;
        maxa := a[i];
      end
      else if a[i] >= maxb then
        maxb := a[i];
    end;
    exit(max(m2 * m7, ifthen(m14 = maxa, m14 * maxb, m14 * maxa)));

  end;

begin

  for i := 1 to 10000 do
  begin
    n := NLIM - random(NLIM div 2);
    for j := 1 to n do
      a[j] := random(30) + 1;
    if simple() <> optimal() then
      writeln('error!');

  end;
  writeln('done!');
  Readln();
end.


