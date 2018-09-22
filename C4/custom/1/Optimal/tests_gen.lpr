program tests_gen;

uses
  SysUtils;

const
  NLIM = 10;
  TLIM = 4;
  VLIM = 20;
var
  infile, anfile: TextFile;
  a: array [1..NLIM] of integer;
  ans, i, j, n: integer;
begin
  Randomize();
  for i := 1 to TLIM do
  begin
    n := NLIM - random(NLIM mod 2);
    for j := 1 to n do
      a[j] := random(VLIM) + 1;

    for j := 1 to n do
      Write(a[j], ' ');
    Writeln();
    Readln(ans);

    Assign(infile, 'tests/0' + IntToStr(i));
    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(infile);
    ReWrite(anfile);
    writeln(infile, n);
    for j := 1 to n do
      writeln(infile, a[j]);
    writeln(anfile, ans);
    Close(infile);
    Close(anfile);
  end;
end.
