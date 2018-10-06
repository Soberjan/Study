program test;

  function simple(): integer;
  begin

  end;

  function optimal(): integer;
  begin

  end;

begin

  for i := 1 to 10000 do
  begin
    if simple() <> optimal() then
      writeln('error!');
  end;
  writeln('done!');
  Readln();
end.


