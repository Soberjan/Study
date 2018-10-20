program tests_gen;

uses
  SysUtils;

const
  NLIM = 10000;
  TLIM = 11;
var
  infile, anfile: TextFile;
  a: array [1..NLIM] of byte;
  ans, i, j, m: integer;
  n: byte;
begin
  Randomize();
  for i := 10 to TLIM do
  begin
    n := 100;
    m := 10000;
    for j := 1 to 5500 do
      a[j] := 1;
    for j := 5500 to 10000 do
      a[j] := 3;

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

n := random(15) + 1;
    m := random(100);
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
