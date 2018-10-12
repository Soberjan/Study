program optimal;

uses
  Math;

var
  n, m, a, b: Int64;

  function optimal(): Int64;

  var
    x, y, q, r: Int64;

  begin
    if m - n <= 0 then
      exit(0);
    if a * 4 <= b then
      exit((m - n) * a);

    q := (m - n) div 4;
    r := (m - n) mod 4;

    x := ifthen(r * a > b, 0, r);
    y := ifthen(r * a > b, q + 1, q);

    exit(x * a + y * b);
  end;

begin
  Readln(n);
  Readln(m);
  Readln(a);
  Readln(b);

  Writeln(optimal());
end.
