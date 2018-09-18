program N37;

uses
  Classes,
  SysUtils, unit1, unit2;

const
  N = 6;
var
  a: array [1..N] of integer;
  i, l, lmax, s, smax: integer;

begin

  for i := 1 to N do
    Readln(a[i]);
  lmax := 0;

  for i := 1 to N do
  begin
    if l = 0 then
      l := l + 1;
    if a[i] < a[i + 1] then
    begin
      l := l + 1;
      s := s + a[i];
    end
    else
    begin
      if lmax < l then
      begin
        lmax := l;
        smax := s;
        l := 0;
        s := 0;
      end;
    end;
  end;

  Writeln(smax);

  Readln();

end.
end.
