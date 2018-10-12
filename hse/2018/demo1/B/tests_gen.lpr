program tests_gen;

uses
  SysUtils;

const
  NLIM = 50;
  TLIM = 12;
  VLIM = 35;
var
  infile, anfile: TextFile;
  a: array [1..NLIM] of integer;
  ans, i, j, n, k: integer;
begin
  Randomize();
  for i := 9 to TLIM do
  begin
    n := random(30) + 1;
    k := random(10);
    for j := 1 to n do
      a[j] := random(VLIM) - 15;

    Writeln(n, ' ', k);
    for j := 1 to n do
      Write(a[j], ' ');
    Writeln();
    Readln(ans);

    Assign(infile, 'tests/0' + IntToStr(i));
    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(infile);
    ReWrite(anfile);
    write(infile, n, ' ', k);
    writeln(infile);
    for j := 1 to n do
      writeln(infile, a[j]);
    writeln(anfile, ans);
    Close(infile);
    Close(anfile);
  end;
end.
