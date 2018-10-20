program optimal;

var
  n, k, unix1, unix2: longint;
  h, m, s: byte;

  function optimal(): longint;
  var
    i: longint;
  begin
    for i := 2 to n do
    begin
      Readln(h, m, s);
      unix2 := h * 3600 + m * 60 + s;
      if (unix1 >= unix2) then
        k := k + 1;
      unix1 := unix2;
    end;
    exit(k);
  end;

begin          
  k := 1;
  Readln(n);
  Readln(h, m, s);
  unix1 := h * 3600 + m * 60 + s;
  Writeln(optimal());
  Readln();
end.


