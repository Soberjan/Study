program simple;

uses
  Math;

var
  a, b, m, n, x, y, s: integer;


begin

  Readln(n);
  Readln(m);
  Readln(a);
  Readln(b);
  s := 0;

  if m <= n then
  begin
    Writeln(s);
    exit;
  end;
  x := m - n;
  y := 0;
  s := x * a + y * b;
  repeat
    y := y + 1;
    x := max(x - 4, 0);
    s := min(s, a * x + b * y);
  until x = 0;
  Writeln(s);
end.


//if m <= n then
//      exit(0);
//    x := m - n;
//    y := 0;
//    s := x * a + y * b;
//    repeat
//      y := y + 1;
//      x := max(x - 4, 0);
//      s := min(s, a * x + b * y);
//    until x = 0;
//    exit(s);



