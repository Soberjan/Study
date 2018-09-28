program optimal;

var
  amr, amd, amn, amdleft, vald, valm, sum, sumt: integer;

begin

  Readln(amr);
  Readln(amd);
  Readln(vald);
  Readln(valm);
  sum := 0;
  sumt := 0;
  amn := 0;

  if valm <= vald then
    if (amd - amr) mod 4 <> 0 then
      sum := ((amd - amr) div 4 + 1) * valm
    else if (amd - amr) mod 4 = 0 then
      sum := ((amd - amr) div 4) * valm;
  if vald * 4 < valm then
    sum := (amd - amr) * vald;

  if (sum = 0) then
    begin
      amn :=  amd - amr;
      sum := (amn div 4) * valm;
      amdleft := amn mod 4;
      if amdleft <> 0 then
      begin
        sumt := amdleft * vald;
        if sumt > valm then
          sum := sum + valm
        else
          sum := sum + vald;
      end;
    end;

  Writeln(sum);
end.




