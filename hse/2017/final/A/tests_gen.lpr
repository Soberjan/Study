program tests_gen;

uses
  SysUtils;

const
  TLIM = 4;
var
  infile, anfile: TextFile;
  ans, i, j, n, h1, m1, h2, m2, d, a : integer;
begin
  Randomize();
  for i := 2 to TLIM do
  begin
    h1 := random(23);
    m1 := random(59);
    h2 := random(72);
    m2 := random(59);
    d := random(25) - 11;
    a := random(25) - 11;
    Writeln(h1, ' ', m1);
    Writeln(h2, ' ', m2);
    Writeln(d, ' ', a);
    Readln(ans);

    Assign(infile, 'tests/0' + IntToStr(i));
    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(infile);
    ReWrite(anfile);
    Writeln(infile, h1, ' ', m1);
    Writeln(infile, h2, m2);
    Writeln(infile, d, a);
    writeln(anfile, ans);
    Close(infile);
    Close(anfile);
  end;
end.
