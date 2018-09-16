program Optimal;

const
  Nlim = 1000;

var
  a: array [1..Nlim] of integer;
  i, N, q, b, c, d, c1, max: integer;

begin
  Readln(N);
  for i := 1 to N do
    Readln(a[i]);

  //N := 10;
  //Randomize();
  //for i := 1 to N do
  //  a[i] := random(19) + 1;
  //
  //for i := 1 to N do
  //  Writeln(a[i]);
  //
  //max := 0;

  Readln();

  for i := 1 to N do
  begin
    if (a[i] mod 7 = 0) and (a[i] > q) then
      q := a[i]
    else if (a[i] mod 2 = 0) and (a[i] > b) then
      b := a[i]
    else if (a[i] mod 14 = 0) and (a[i] > c) then
      c := a[i]
    else if (a[i] > max) and (a[i] <> q) and (a[i] <> b) and (a[i] <> c) then
      max := a[i]
    else if (a[i] = c) then c1 := a[i];
  end;

  if (max * c > q * b) and (max * c > q * c) and (max * c > b * c) and (max * c > c * c1) then
    Writeln(max * c)
  else if (q * b > b * c) and (q * b > q * c) and (q * b > c * c1) then
    Writeln(q * b)
  else if (b * c > q * c) and (q * b > c * c1) then
    Writeln(b * c)
  else if (q * c > c * c1) then
    Writeln(q * c)
  else if c * c1 > 0 then
    Writeln(c * c1)
  else
    Writeln('0');



  Readln();

end.
