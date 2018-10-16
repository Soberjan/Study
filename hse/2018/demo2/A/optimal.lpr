program optimal;

const
  Nlim = 15;
var
  a: array[1..Nlim] of integer;
  n, k: longint;
  h, m, s: shortint;

  function optimal(): longint;
  var
    i: longint;
  begin
    for i := 2 to n do
    begin
      Readln(h, m, s);
      a[i] := h * 3600 + m * 60 + s;
      if a[i-1] >= a[i] then
        k := k + 1;
    end;
    exit(k);
  end;

begin
  k := 1;
  Readln(n);
  Readln(h, m, s);
  a[1] := h * 3600 + m * 60 + s;
  Writeln(optimal());
  Readln();

end.


