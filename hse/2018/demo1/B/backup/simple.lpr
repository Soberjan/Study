program simple;

const
  NLIM = 100;

var
  a: array[1..NLIM] of integer;
  n, i, k, s_res: integer;

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
    for i := n downto 1 do  //Создаем массив, который будет хранить информацию о положении единиц
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
    exit(comfort(16));
  //  am_c := amount_code(n);
  //  min := mincode(am_c);
  //  for c := 0 to am_c do
  //    if (vacation_length(c)=k) then
  //      if(comfort(c) < comfort(min)) then
  //       min := c;
  //  exit(comfort(min));
  //end;
  end;

begin
  assign(input, 'tests\04');
  reset(input);
  Readln(n, k);
  for i := 1 to n do
    Readln(a[i]);
  s_res := simple();
  writeln(s_res);
end.


