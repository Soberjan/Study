program tests_gen;

uses
  SysUtils;

const
  NLIM = 100;
  TLIM = 10;
var
  infile, anfile: TextFile;
  a: array [1..NLIM] of byte;
  ans, i, j, m: integer;
  n: byte;
begin
  Randomize();
  for i := 2 to TLIM do
  begin
    n := random(9) + 1;
    m := random(15);
    for j := 1 to m do
      a[j] := random(n - 1) + 1;

    Writeln(n, ' ', m);
    for j := 1 to m do
      Write(a[j], ' ');
    Writeln();
    Readln(ans);

    Assign(infile, 'tests/0' + IntToStr(i));
    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(infile);
    ReWrite(anfile);
    writeln(infile, n, ' ', m);
    for j := 1 to m do
      write(infile, a[j], ' ');
    writeln(anfile, ans);
    Close(infile);
    Close(anfile);
  end;
end.
