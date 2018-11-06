program tests_gen;

uses
  SysUtils;

const
  NLIM = 100;
  TLIM = 4;
  VLIM = 20;
var
  infile, anfile: TextFile;
  a: array [1..NLIM, 1..NLIM] of char;
  ans, i, j, h, n, m: shortint;
begin
  Randomize();
  for i := 1 to TLIM do
  begin
    n := random(10);
    m := random(10);
    for j := 1 to n do
    begin
      for h := 1 to m do






    end;

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
