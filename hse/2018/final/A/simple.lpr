program simple;

var
  a: array[1..10000] of byte;
  m, i: integer;
  n: byte;

function simple(): integer;
var
  b: array[1..100] of byte;
  i, maxloops, first_participant: integer;
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
   read(a[i]);

  Writeln(simple());
end.

