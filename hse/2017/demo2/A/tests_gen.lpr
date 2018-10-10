program tests_gen;

uses
  SysUtils;

const
  NLIM = 5;
  TLIM = 6;
var
  infile, anfile: TextFile;
  ans, i, j, n, y, mth, d, h, m, s, ms: integer;
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
      y := random(20) + 2000;
      mth := random(11) + 1;
      d := (30) + 1;
      h := random(23);
      m := random(59);
      s := random(59);
      ms := random(59);
      Write(y, ' ', mth, ' ', d, ' ', h, ' ', m, ' ', s, ' ', ms);
      Writeln();
      Write(infile, y, ' ', mth, ' ', d, ' ', h, ' ', m, ' ', s, ' ', ms);
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
