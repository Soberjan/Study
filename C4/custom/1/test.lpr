program test;

const
  NLIM = 20;

var
  a: array[1..NLIM] of integer;
  i, j, n: integer;

  function simple(): integer;
  var
    r, i, j: integer;
  begin
    r := 0;
    for i := 1 to n - 1 do
    begin
      for j := i + 1 to n do
        if (r < a[i] * a[j]) and (a[i] * a[j] mod 14 = 0) then
          r := a[i] * a[j];
    end;
    exit(r);
  end;

  function optimal(): integer;

  var
    ch, i, m2, m7, m14, max: integer;
  begin
    q := 0;
    b := 0;
    c := 0;
    max := 0;
    ch := 0;
    for i := 1 to n do
    begin
      if (a[i] mod 14 = 0) and (a[i] > m14) then
        c := ch;
      if (a[i] mod 7 = 0) and (a[i] > q) and (a[i] mod 14 <> 0) then
        q := ch;
      if (a[i] mod 2 = 0) and (a[i] > b) and (a[i] mod 14 <> 0) then
        b := ch;
      if (a[i] > max) and (a[i] <> q) and (a[i] <> b) then
        max := ch;
    end;

    if (max * c > q * b) and (max * c > q * c) and (max * c > b * c) then
      exit(max * c);
    if (q * b > b * c) and (q * b > q * c) and (q * b > max * c) then
      exit(q * b);
    if (b * c > q * c) and (b * c > q * b) and (b * c > max * c) then
      exit(b * c);
    if (q * c > b * c) and (q * c > q * b) and (q * c > max * c) then
      exit(q * c);
    if (max * c = 0) and (q * b = 0) and (q * c = 0) and (b * c = 0) then
      exit(0);
     //exit(0);
  end;

begin

  for i := 1 to 1000 do
  begin
    n := NLIM - random(NLIM div 2);
    for j := 1 to n do
      a[j] := random(30) + 1;
    if simple() <> optimal() then
    begin
      writeln('ERROR!');
      optimal();

    end;
  end;
  Readln();

end.




