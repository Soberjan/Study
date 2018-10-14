program simple;
uses
  Math;

var
  h1, m1, h2, m2, h3, m3, d, a, belt, days: integer;

begin
  //assign(input, 'tests\01');
  //reset(input);
  Read(h1, m1, h2, m2, d, a);
  days := 0;
  h3 := 0;
  m3 := 0;

  belt := -1 * (d - a);
  if abs(d - a) > 13 then
    begin
    if d - a < 0 then
      belt := -1 * (26 - belt)
    else if d - a > 0 then
      belt := 26 - belt;
    days := days + 1;
    end;

  days := days + (h2 div 24);
  h1 := ifthen(h2 > 24, h1 + (h2 mod 24), h1 + h2);

  m3 := m1 + m2;
  if m1 + m2 > 60 then
    begin
    m3 := m1 + m2 - 60;
    h3 := h3 + 1;
    end;

  h3 := h3 + h1 + belt;
  while h3 > 24 do
  begin
    h3 := h3 - 24;
    days := days + 1;
  end;

  Writeln(h3, ' ', m3, ' ', days);
  readln();

end.

