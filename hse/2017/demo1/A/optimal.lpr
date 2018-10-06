program optimal;
uses math;

var
    n, m, a, b, x, y, q, r: integer;

  begin
    Readln(n);
    Readln(m);
    Readln(a);
    Readln(b);

    if m - n <= 0 then
    begin
      Writeln(0);
      exit;
    end;
    if a * 4 <= b then
    begin
      Writeln((m - n) * a);
      exit;
    end;

    q := (m - n) div 4;
    r := (m - n) mod 4;
    x := ifthen(r * a > b, 0, r);
    y := ifthen(r * a > b, q + 1,q);

    Writeln(x * a + y * b);
end.

