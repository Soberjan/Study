program simple;

var
  a: array[1..10000] of byte;
  m, i: smallint;
  n: byte;

  function simple(): byte;
  var
    b: array[1..100] of byte;
    i, leader: smallint;
  begin
    leader := a[1];
    FillByte(b, n, 0);
    for i := 1 to m do
    begin
      b[a[i]] += 1;
      if b[a[i]] > b[leader] then
        leader := a[i];
    end;
    exit(leader);
  end;

begin
  Readln(n, m);
  for i := 1 to m do
    Read(a[i]);

  Writeln(simple());
end.
