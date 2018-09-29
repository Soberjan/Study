program optimal;

var
  num, i, n, m2, m7, m14, adm14, max: integer;

begin
  Readln(n);

  m7 := 0;
  m2 := 0;
  m14 := 0;
  max := 0;
  num := 0;

  for i := 1 to n do
  begin
    Readln(num);
    if (num mod 14 = 0) and (num = m14) then
      adm14 := num;
    if (num mod 14 = 0) and (num > m14) then
    begin
      if m14 > adm14 then
        adm14 := m14;
      m14 := num;
    end;
    if (num mod 7 = 0) and (num > m7) and (num mod 14 <> 0) then
      m7 := num;
    if (num mod 2 = 0) and (num > m2) and (num mod 14 <> 0) then
      m2 := num;
    if (num > max) and (num <> m7) and (num <> m2) and (num <> m14) and
      (num <> adm14) then
      max := num;
  end;

  if (max * m14 > m7 * m2) and (max * m14 > m7 * m14) and
    (max * m14 > m2 * m14) and (max * m14 > m14 * adm14) then
    Writeln(max * m14);
  if (m7 * m2 > m2 * m14) and (m7 * m2 > m7 * m14) and (m7 * m2 > max * m14) and
    (m7 * m2 > m14 * adm14) then
    Writeln(m7 * m2);
  if (m2 * m14 > m7 * m14) and (m2 * m14 > m7 * m2) and
    (m2 * m14 > max * m14) and (m2 * m14 > m14 * adm14) then
    Writeln(m2 * m14);
  if (m7 * m14 > m2 * m14) and (m7 * m14 > m7 * m2) and
    (m7 * m14 > max * m14) and (m7 * m14 > m14 * adm14) then
    Writeln(m7 * m14);
  if (m14 * adm14 > max * m14) and (m14 * adm14 > m7 * m2) and
    (m14 * adm14 > m2 * m14) and (m14 * adm14 > m7 * m14) then
    Writeln(m14 * adm14);
  if (max * m14 = 0) and (m7 * m2 = 0) and (m7 * m14 = 0) and
    (m2 * m14 = 0) and (m14 * adm14 = 0) then
    Writeln(0);
end.
