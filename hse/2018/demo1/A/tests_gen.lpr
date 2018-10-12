program tests_gen;

uses
  SysUtils;

const
  NLIM = 4;
  TLIM = 6;
  VLIM = 10;
var
  infile, anfile: TextFile;
  a: array [1..NLIM] of integer;
  ans, i, j, n: integer;
begin
  Randomize();
  for i := 4 to TLIM do
  begin

    a[1] := random(10) + 1;
    a[2] := random(15) + 8;
    a[3] := random(VLIM) + 1;
    a[4] := random(VLIM) +5;

    for j := 1 to 4 do
      Writeln(a[j]);
    Writeln();
    Readln(ans);

    Assign(infile, 'tests/0' + IntToStr(i));
    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(infile);
    ReWrite(anfile);
    for j := 1 to 4 do
      writeln(infile, a[j]);
    writeln(anfile, ans);
    Close(infile);
    Close(anfile);
  end;
end.
