program simple;
var
  a: array[1..100, 1..100] of char;
  m, n, i, j: shortint;
  isle: boolean;
  s: smallint;

begin
  assign(input, 'tests\00');
  reset(input);

  Readln(n, m);
  for i := 1 to n do
  begin
    for j := 1 to m do
      Read(a[i, j]);
    Readln();
  end;
  for i := 1 to n do
  begin
    Writeln();
    for j := 1 to m do
      Write(a[i, j]);
  end;

  s := 0;
  isle := false;
  for i := 1 to n do
    for j := 1 to m do
    begin
      if (a[i,j] = '/') or (a[i,j] = '\') then
      begin
        if isle = false then
          s += 1;
        isle := not isle;
      end;
      if (a[i, j] = '.') and (isle = true) then
        s += 1;
    end;

  Writeln();
  Writeln(s);
end.

