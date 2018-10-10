program simple;

type
  time = record
    h, m, s : integer;
  end;
var
  i, n, k: integer;
  a, a1 : time;
begin
  Readln(n);
  Read(a1.h, a1.m, a1.s);
  k := 1;

  for i := 1 to n - 1 do
  begin
    Read(a.h, a.m, a.s);
    if a.h < a1.h then
      k := k + 1;
    if a.h = a1.h then
    begin
      if a.m < a1.m then
        k := k + 1;
      if a.m = a1.m then
      begin
        if a.s <= a1.s then
          k := k + 1;
      end;
    end;
    a1.h := a.h;
    a1.m := a.m;
    a1.s := a.s;
  end;

  Writeln(k);

end.




