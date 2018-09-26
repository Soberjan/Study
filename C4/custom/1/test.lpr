program test;

const
  TLIM = 1000;

var
  i, j : integer;

  function simple(): integer;
  const
    NLIM = 10;
    //TLIM = 4;
    VLIM = 20;
  var
    a: array [1..NLIM] of integer;
    r, i, j, n: integer;
  begin
    //for z := 1 to TLIM do
    //begin
    Randomize();
    n := NLIM - random(NLIM mod 2);
    for j := 1 to n do
      a[j] := random(VLIM) + 1;
    r := 0;
    for i := 1 to N - 1 do
    begin
      for j := i + 1 to N do
        if (r < a[i] * a[j]) and (a[i] * a[j] mod 14 = 0) then
          r := a[i] * a[j];
    end;
    simple := (r);

    //end;
  end;

  function optimal(): integer;

  const
    NLIM = 10;
    //TLIM = 4;
    VLIM = 20;
  var
    a: array[1..NLIM] of integer;
    ch, i, n, q, b, c, j, max: integer;
  begin
    //for z := 1 to TLIM do
    //begin
    Randomize();
    n := NLIM - random(NLIM mod 2);
    for j := 1 to n do
      a[j] := random(VLIM) + 1;
    q := 0;
    b := 0;
    c := 0;
    max := 0;
    ch := 0;
    for i := 1 to n do
    begin
      if (a[i] mod 14 = 0) and (a[i] > c) then
        c := ch;
      if (a[i] mod 7 = 0) and (a[i] > q) and (a[i] mod 14 <> 0) then
        q := ch;
      if (a[i] mod 2 = 0) and (a[i] > b) and (a[i] mod 14 <> 0) then
        b := ch;
      if (a[i] > max) and (a[i] <> q) and (a[i] <> b) then
        max := ch;
    end;

    if (max * c > q * b) and (max * c > q * c) and (max * c > b * c) then
      optimal := (max * c);
    if (q * b > b * c) and (q * b > q * c) and (q * b > max * c) then
      optimal := (q * b);
    if (b * c > q * c) and (b * c > q * b) and (b * c > max * c) then
      optimal := (b * c);
    if (q * c > b * c) and (q * c > q * b) and (q * c > max * c) then
      optimal := (q * c);
    if (max * c = 0) and (q * b = 0) and (q * c = 0) and (b * c = 0) then
      optimal := (0);
    //end;
  end;

begin

  for i := 1 to TLIM do
  if simple() <> optimal() then
    writeln('ERROR!');



  Readln();

end.




