program simple;


type
  Time = record
    k, h, m, s: integer;
  end;

  const
    Nlim = 15;
var
  a: array[1..Nlim] of Time;
  i, n, k: integer;

  function less(r, l : Time) : boolean;

  begin
    exit((r.h < l.h) or
        ((r.h = l.h) and (r.m < l.m)) or
        ((r.h = l.h) and (r.m = l.m)) and (r.s <= l.s));
  end;

  function simple() : integer;
  var
    i : integer;
  begin
    for i := 2 to n do
    begin
      readln(a[i].h, a[i].m, a[i].s);
      if less(a[i], a[i-1]) then
        k+=1;
    end;
    exit(k);
  end;
begin
Readln(n);
Readln(a[1].h, a[1].m, a[1].s);
k := 1;
Writeln(simple());
end.







