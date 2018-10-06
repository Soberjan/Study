program tests_gen;

uses
  SysUtils;

const
  NLIM = 5;
  TLIM = 6;
var
  infile, anfile: TextFile;
  ans, i, j, n, h, m, s: integer;
begin
  Randomize();
  for i := 3 to TLIM do
  begin
    n := NLIM - random(NLIM mod 2);

    Assign(infile, 'tests/0' + IntToStr(i));
    ReWrite(infile);

    writeln(infile, n);
    for j := 1 to n do
    begin
      h := random(23);
      m := random(59);
      s := random(59);
      Write(h, ' ', m, ' ', s);
      Writeln();
      Write(infile, h, ' ', m, ' ', s);
      Writeln(infile);
    end;

    Readln(ans);
    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(anfile);
    writeln(anfile, ans);

    Close(infile);
    Close(anfile);
  end;
end.
