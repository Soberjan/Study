program simple;

var
  amr, amd, vald, valm, sum, sumt: integer;

begin

  sum := 0;
  sumt := 0;
  Readln(amr);
  Readln(amd);
  Readln(vald);
  Readln(valm);
  if valm <= vald then
  begin
    while amd > amr do
    begin
      amr := amr + 4;
      sum := sum + valm;
    end;
  end;
  if vald * 4 < valm then
  begin
    while amd > amr do
    begin
      amr := amr + 1;
      sum := sum + vald;
    end;
  end;

  while amd > amr do
  begin
    if amd - amr >= 4 then
    begin
      amr := amr + 4;
      sum := sum + valm;
    end
    else if (amd - amr < 4) and (amd - amr <> 0) then
    begin
      while amd > amr do
      begin
        sumt := sumt + vald;
        amr := amr + 1;
      end;
      if sumt >= valm then
        sum := sum + valm
      else if sumt < valm then
        sum := sumt + sum;
    end;
  end;

  Writeln(sum);
end.






