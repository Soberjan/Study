program test;


const
  NLIM = 30;

var
  a: array[1..100] of integer;
  i, j, n, k, simple_res, optimal_res: integer;

  function vacation_length(c: integer): integer;
  var
    k: integer;
  begin
    k := 1;
    while c div 2 > 0 do
    begin
      if c mod 2 = 1 then
        k := k + 1;
      c := c div 2;
    end;
    exit(k);
  end;

  function comfort(c: integer): integer;

  var
    b: array[1..NLIM] of integer;
    i, j, max, min: integer;
  begin
    if c = 0 then
    begin
      min := a[1];
      max := a[1];
      for j := 1 to n do
        if a[j] > max then
          max := a[j];
      for j := 1 to n do
        if a[j] < min then
          min := a[j];
      exit(max - min);
    end;
    for i := n downto 1 do
      //Создаем массив, который будет хранить информацию о положении единиц
    begin
      b[i] := c mod 2;
      c := c div 2;
    end;
    for i := 1 to n do
    begin
      if b[i] <> 1 then
      begin
        min := a[i];
        max := a[i];
        break;
      end;
    end;
    for i := 1 to n do
    begin
      if b[i] <> 1 then
      begin
        for j := i + 1 to n do
          if (a[j] > max) and (b[j] <> 1) then
            max := a[j];
        for j := i + 1 to n do
          if (a[j] < min) and (b[j] <> 1) then
            min := a[j];
      end;
    end;
    exit(max - min);
  end;

  function mincode(n: integer): integer;
  var
    i, i1, min: integer;
  begin
    if k = 1 then
      exit(1);
    for i := 0 to n do
    begin
      min := 1;
      i1 := i;
      while i1 div 2 > 0 do
      begin
        if i1 mod 2 = 1 then
          min := min + 1;
        i1 := i1 div 2;
      end;
      if min = k then
        exit(i);
    end;
  end;

  function amount_code(n: integer): integer;
  var
    s: integer;
  begin
    s := 1;
    for i := 1 to n do
      s := s * 2;
    exit(s - 1);
  end;

  function simple(): integer;
  var
    min, am_c, c: integer;
  begin
    if n < k then
      exit(0);
    if k = 0 then
      exit(comfort(0));
    am_c := amount_code(n);
    min := mincode(am_c);
    for c := 0 to am_c do
      if (vacation_length(c) = k) then
        if (comfort(c) < comfort(min)) then
          min := c;
    exit(comfort(min));
  end;

  function optimal(): integer;
  var
    i, j, max, t, min, max2: integer;
  begin
    max := 0;
    t := 0;
    if (n - k <= 1) then
      exit(0);
    if (k > 0) then
    begin
      for i := 1 to k do
      begin
        max := i;
        for j := i + 1 to N do
          if abs(A[j]) > abs(A[max]) then
            max := j;
        t := a[max];
        a[max] := a[i];
        a[i] := t;
      end;
    end;
    min := a[k + 1];
    max2 := a[k + 1];
    for i := k + 1 to n do
      if a[i] < min then
        min := a[i];
    for i := k + 1 to n do
      if a[i] > max2 then
        max2 := a[i];
    exit(max2 - min);
  end;

begin

  for i := 1 to 10000 do
  begin
    Writeln('WIP');
    k := random(10) + 1;
    n := NLIM - random(NLIM div 2);
    for j := 1 to n do
      a[j] := random(30) - 15;
    simple_res := simple();
    optimal_res := optimal();
    if simple_res <> optimal_res then
      writeln('error!');

  end;
  writeln('done!');
  Readln();
end.



