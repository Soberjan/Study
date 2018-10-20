program tests_gen;

uses
  SysUtils;

type
  Arrive_time = record
    a, b: integer;
  end;

var
  infile, anfile: TextFile;
  c, ans: array [1..100] of Arrive_time;
  help_ans, i, j, n: integer;
begin
  Randomize();
  for i := 4 to 5 do
  begin
    n := 12 - random(8);
    for j := 1 to n do
    begin
      c[j].a := random(20);
      repeat
      c[j].b := random(20);
      until c[j].b >= c[j].a;
    end;

    Writeln(n);
    for j := 1 to n do
      Writeln(c[j].a, ' ', c[j].b);
    Writeln();
    Readln(help_ans);
    for j := 1 to help_ans do
      Readln(ans[j].a, ans[j].b);

    Assign(infile, 'tests/0' + IntToStr(i));
    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(infile);
    ReWrite(anfile);
    writeln(infile, n);
    for j := 1 to n do
      writeln(infile, c[j].a, ' ', c[j].b);
    for j := 1 to help_ans do
      writeln(anfile, ans[j].a, ' ', ans[j].b);
    Close(infile);
    Close(anfile);
    writeln();
  end;
end.
