program simple;

const
  NLIM = 10000;
var
  a: array[1..NLIM] of byte;
  m, i: smallint;
  n: byte;

  function simple(): byte;
  var
    b: array[1..100] of byte;
    i, maxloops: smallint;
    first_participant: byte;
  begin
    for i := 1 to n do
      b[i] := 0;
    maxloops := 0;

    for i := 1 to m do
    begin
      b[a[i]] += 1;
      if b[a[i]] > maxloops then
      begin
        maxloops := b[a[i]];
        first_participant := a[i];
      end;
    end;
    exit(first_participant);
  end;

begin
  Readln(n, m);
  for i := 1 to m do
    Read(a[i]);

  Writeln(simple());
end.
