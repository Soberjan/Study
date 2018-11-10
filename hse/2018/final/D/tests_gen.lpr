program tests_gen;

uses
  SysUtils;

var
  infile, anfile: TextFile;
  a: array [1..100] of integer;
  ans, i, j, n: integer;
begin
  Randomize();
  for i := 2 to 5 do
  begin
    n := 25 - random(5);
    for j := 1 to n do
      a[j] := random(20);

    Writeln(n);
    for j := 1 to n do
      Write(Format('%-4d', [a[j]]));
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
    writeln();
  end;
end.
