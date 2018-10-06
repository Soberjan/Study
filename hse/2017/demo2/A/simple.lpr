program simple;

var
  i, n, h, m, s, h1, m1, s1, k: integer;

begin
  Readln(n);
  Read(h1, m1, s1);
  k := 1;

  for i := 1 to n - 1 do
  begin
    Read(h, m, s);
    if h < h1 then
      k := k + 1;
    if h = h1 then
    begin
      if m < m1 then
        k := k + 1;
      if m = m1 then
      begin
        if s <= s1 then
          k := k + 1;
      end;
    end;
    h1 := h;
    m1 := m;
    s1 := s;
  end;

  Writeln(k);

end.




