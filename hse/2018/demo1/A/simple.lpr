program simple;

uses
  Math;

var
  m, n: Int64;
  a, b: integer;

  function simple(): Int64;
  var
    x, s: Int64;
    y: integer;
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

begin

  Readln(n);
  Readln(m);
  Readln(a);
  Readln(b);

  Writeln(simple());
end.















