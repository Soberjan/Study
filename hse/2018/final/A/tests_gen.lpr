program tests_gen;

uses
  SysUtils;

const
  NLIM = 10000;

var
  infile, anfile: TextFile;
  a: array [1..NLIM] of byte;
  ans, i, j, m: integer;
  n: byte;
  fmt, s: string;

  procedure CreateTest(i, n, m: integer);
  begin
    for j := 1 to m do
      a[j] := random(n - 1) + 1;

    Writeln(n, ' ', m);
    for j := 1 to m do
      Write(a[j], ' ');
    Writeln();
    Readln(ans);


    fmt := '%.2d';
    s := Format(fmt, [i]);

    Assign(infile,'tests\' + s);
    Assign(anfile, 'tests\' + s + '.a');
    ReWrite(infile);
    ReWrite(anfile);
    writeln(infile, n, ' ', m);
    for j := 1 to m do
      Write(infile, a[j], ' ');
    writeln(anfile, ans);
    Close(infile);
    Close(anfile);
  end;

begin
  Randomize();
  for i := 2 to 2 do
  begin
    n := random(15) + 1;
    m := random(10);
   CreateTest(i, n, m);
  end;
  //for i := 10 to 13 do
  //begin
  //  n := 100;
  //  m := 10000;
  //  CreateTest(i, n, m);
  //end;
end.

