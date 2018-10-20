program simple;


type
  Time = record
    k, h, m, s: integer;
  end;

const
  Nlim = 100000;

var
  a: array[1..Nlim] of Time;
  i, n, k: integer;

  function less(l, r: Time): boolean;
  begin
    exit((r.h < l.h) or ((r.h = l.h) and (r.m < l.m)) or
      ((r.h = l.h) and (r.m = l.m)) and (r.s <= l.s));
  end;

  function simple(): longint;
  var
    k, j: longint;
  begin
    k := 1;
    for j := 2 to n do
    begin
      if less(a[j - 1], a[j]) then
        k += 1;
    end;
    exit(k);
  end;

begin
  Readln(n);
  for i := 1 to n do
    Readln(a[i].h, a[i].m, a[i].s);
  Writeln(simple());
end.






