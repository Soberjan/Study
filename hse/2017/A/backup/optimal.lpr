program optimal;

var
  kr, kd, vald, valm, sum, sumt: integer;

begin

  Readln(kr);
  Readln(kd);
  Readln(vald);
  Readln(valm);
  sum := 0;
  sumt := 0;

  if valm <= vald then
    if (kd - kr) mod 4 <> 0 then
      sum := (kd-kr) div 4 + 1;

  if vald * 4 < valm then
  begin
    while kd > kr do
    begin
      kr := kr + 1;
      sum := sum + vald;
    end;
  end;




end.

