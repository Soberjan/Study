program optimal;

type
  Time = record
    h, m, s: longint;
  end;

const
  Nlim = 15;
var
  a: array[1..Nlim] of Time;
  n, k: longint;

  function optimal(): longint;
  var
    i: longint;
  begin
    for i := 2 to n do
    begin
      Readln(a[i].h, a[i].m, a[i].s);
      if a[i - 1].h * 3600 + a[i - 1].m * 60 + a[i - 1].s >=
         a[i].h * 3600 + a[i].m * 60 + a[i].s then
        k := k + 1;
    end;
    exit(k);
  end;

begin
  k := 1;
  Readln(n);
  Readln(a[1].h, a[1].m, a[1].s);
  Writeln(optimal());
  Readln();

end.


