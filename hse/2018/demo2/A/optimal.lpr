program optimal;

var
  n: longint;    
  function optimal(): longint;
  var
    i, unix1, unix2, k: longint;
    h, m, s: byte;
  begin
    Readln(h, m, s);
    unix1 := h * 3600 + m * 60 + s;
    k := 1;
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
  Readln(n);
  Writeln(optimal());
  Readln();
end.


