program optimal;
uses math;
var
  num, i, n, m2, m7, m14, maxa, maxb: integer;

begin
  Readln(n);

  m2 := 0;
  m7:= 0;
  m14 := 0;
  maxa := 0;
  maxb := 0;
  num := 0;

  for i := 1 to n do
  begin
    Readln(num);
    if (num mod 14 = 0) and (num > m14) then
      m14 := num;
    if (num mod 7 = 0) and (num > m7) and (num mod 14 <> 0) then
      m7 := num;
    if (num mod 2 = 0) and (num > m2) and (num mod 14 <> 0) then
      m2 :=num;
    if (num >= maxa) then
    begin
      maxa := num;
      maxb := maxa;
    end
    else if num >= maxb then
      maxb := num;
  end;
Writeln(max(m2 * m7, ifthen(m14 = maxa, m14 * maxb, m14 *maxa)));

end.
