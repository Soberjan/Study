program test;
uses math;
var
  i, n, m, a, b: integer;

  function simple(): integer;
  var
    x, y, s: integer;
  begin
    if m <= n then
      exit(0);
    x := m - n;
    y := 0;
    s := x * a + y * b;
    repeat
      y := y + 1;
      x := max(x - 4, 0);
      s := min(s, a * x + b * y);
    until x = 0;
    exit(s);
  end;

  function optimal(): integer;

  var
    x, y, q, r: integer;

  begin
    if m - n <= 0 then
      exit(0);
    if a * 4 <= b then
      exit((m - n) * a);

    q := (m - n) div 4;
    r := (m - n) mod 4;

    x := ifthen(r * a > b, 0, r);
    y := ifthen(r * a > b, q + 1,q);

    exit(x * a + y * b);
  end;

begin
  for i := 1 to 1000 do
  begin
    n := random(10);
    m := random(20) + 5;
    a := random(15) + 1;
    b := random(20) + 10;
    if simple() <> optimal() then
      writeln('error!');
  end;
  writeln('done!');
end.




