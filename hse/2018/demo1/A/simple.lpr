program simple;

uses
  Math;

var
  a, b, m, n: QWord;

  function simple(): QWord;
  var
    x, y, s: QWord;
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















