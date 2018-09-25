program optimal;

var
  ch, i, n, q, b, c, max: integer;

begin
  Readln(n);

  q := 0;
  b := 0;
  c := 0;
  max := 0;
  ch := 0;

  for i := 1 to n do
  begin
    Readln(ch);
    if (ch mod 14 = 0) and (ch > c) then
      c := ch;
    if (ch mod 7 = 0) and (ch > q) and (ch mod 14 <> 0) then
      q := ch;
    if (ch mod 2 = 0) and (ch > b) and (ch mod 14 <> 0) then
      b := ch;
    if (ch > max) and (ch <> q) and (ch <> b) then
      max := ch;
  end;

  if (max * c > q * b) and (max * c > q * c) and (max * c > b * c) then
    Writeln(max * c);
  if (q * b > b * c) and (q * b > q * c) and (q * b > max * c) then
    Writeln(q * b);
  if (b * c > q * c) and (b * c > q * b) and (b * c > max * c) then
    Writeln(b * c);
  if (q * c > b * c) and (q * c > q * b) and (q * c > max * c) then
    Writeln(q * c);
  if (max * c = 0) and (q * b = 0) and (q * c = 0) and (b * c = 0) then
    Writeln(0);

  Readln();

end.
