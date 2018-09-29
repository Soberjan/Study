program test;

var
  i, simple_res, optimal_res, amr, amd, vald, valm: integer;

  function simple(amr, amd, vald, valm : integer): integer;
  var
    sumt, sum : integer;
  begin
    sum := 0;
    sumt := 0;

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

    exit(sum);

  end;

  function optimal(amr, amd, vald, valm : integer): integer;

  var
    amn, amdleft, sumt, sum: integer;

  begin
    amn := 0;
    sumt := 0;
    sum := 0;

    if (amd < amr) then
      exit(0);

    if valm <= vald then
      if (amd - amr) mod 4 <> 0 then
        sum := ((amd - amr) div 4 + 1) * valm
      else if (amd - amr) mod 4 = 0 then
        sum := ((amd - amr) div 4) * valm;
    if vald * 4 < valm then
      sum := (amd - amr) * vald;

    if (sum = 0) then
    begin
      amn := amd - amr;
      sum := (amn div 4) * valm;
      amdleft := amn mod 4;
      if amdleft <> 0 then
      begin
        sumt := amdleft * vald;
        if sumt >= valm then
          sum := sum + valm
        else
          sum := sum + sumt;
      end;
    end;

    exit(sum);
  end;

begin
  for i := 1 to 1000 do
  begin
    amr := random(10);
    amd := random(20) + 5;
    vald := random(15) + 1;
    valm := random(20) + 10;
    simple_res := simple(amr, amd, vald, valm);
    Writeln(simple_res);
    optimal_res := optimal(amr, amd, vald, valm);
    Writeln(optimal_res);

    if simple_res <> optimal_res then
    begin
      writeln('ERROR!');
      optimal(amr, amd, vald, valm);
    end;
  end;
  Readln();

end.




