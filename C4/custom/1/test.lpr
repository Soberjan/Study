program test;

const
  NLIM = 10;

var
  a: array[1..NLIM] of integer;
  i, j, n, simple_res, optimal_res: integer;

  function simple(): integer;
  var
    r, i, j: integer;
  begin
    r := 0;
    for i := 1 to n - 1 do
    begin
      for j := i + 1 to n do
        if (a[i] * a[j] > r) and (a[i] * a[j] mod 14 = 0) then
          r := a[i] * a[j];
    end;
    exit(r);
  end;

  function optimal(): integer;
  var
    i, m2, m7, m14, adm14, max: integer;
  begin
    m2 := 0;
    m7 := 0;
    m14 := 0;
    max := 0;
    adm14 := 0;
    for i := 1 to n do
    begin
      if (a[i] mod 14 = 0) and (a[i] = m14) then
        adm14 := a[i];
      if (a[i] mod 14 = 0) and (a[i] > m14) then
      begin
        if m14 > adm14 then
          adm14 := m14;
        m14 := a[i];
      end;
      if (a[i] mod 7 = 0) and (a[i] > m7) and (a[i] mod 14 <> 0) then
        m7 := a[i];
      if (a[i] mod 2 = 0) and (a[i] > m2) and (a[i] mod 14 <> 0) then
        m2 := a[i];
      if (a[i] > max) and (a[i] <> m7) and (a[i] <> m2) and (a[i] <> m14) and (a[i] <> adm14) then
        max := a[i];
    end;

    if (max * m14 > m7 * m2) and (max * m14 > m7 * m14) and (max * m14 > m2 * m14) and (max * m14 > m14 * adm14) then
      exit(max * m14);
    if (m7 * m2 > m2 * m14) and (m7 * m2 > m7 * m14) and (m7 * m2 > max * m14) and (m7 * m2 > m14 * adm14) then
      exit(m7 * m2);
    if (m2 * m14 > m7 * m14) and (m2 * m14 > m7 * m2) and (m2 * m14 > max * m14) and (m2 * m14 > m14 * adm14) then
      exit(m2 * m14);
    if (m7 * m14 > m2 * m14) and (m7 * m14 > m7 * m2) and (m7 * m14 > max * m14) and (m7 * m14 > m14 * adm14) then
      exit(m7 * m14);
    if (m14 * adm14 > max * m14) and (m14 * adm14 > m7 * m2) and (m14 * adm14 > m2 * m14) and (m14 * adm14 > m7 * m14) then
      exit(m14 * adm14);
    if (max * m14 = 0) and (m7 * m2 = 0) and (m7 * m14 = 0) and (m2 * m14 = 0) and (m14 * adm14 = 0) then
      exit(0);
  end;

begin

  for i := 1 to 1000 do
  begin
    n := NLIM - random(NLIM div 2);
    writeln(n);
    for j := 1 to n do
      a[j] := random(30) + 1;

    simple_res := simple();
    Writeln(simple_res);
    optimal_res := optimal();
    Writeln(optimal_res);

    if simple_res <> optimal_res then
    begin
      writeln('ERROR!');
      optimal();

    end;
  end;
  Readln();

end.




