program simple;

var
  kr, kd, vald, valm, sum, sumt: integer;

begin

  Readln(kr);
  Readln(kd);
  Readln(vald);
  Readln(valm);
  sum := 0;
  sumt := 0;

  Readln();

  if valm <= vald then
  begin
    while kd > kr do
    begin
      kr := kr + 4;
      sum := sum + valm;
    end;
  end;
  if vald * 4 < valm then
  begin
    while kd > kr do
    begin
      kr := kr + 1;
      sum := sum + vald;
    end;
  end;

  while kd > kr do
  begin
    if kd - kr >= 4 then
    begin
      kr := kr + 4;
      sum := sum + valm;
    end
    else if kd - kr < 4 then
    begin
      kr := kr + 1;
      sumt := sumt + vald;
    end;
  end;
  if sumt > valm then
    sum := sum + valm
  else
    sum := sumt + sum;
  Writeln(sum);

  Readln();

end.






