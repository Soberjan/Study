program tests_gen;

uses
  SysUtils;

var
  infile, anfile: TextFile;
  ans, i, n, k, x: longint;


begin
  Randomize();
  for i := 6 to 10 do
  begin
    n := random(40) + 2;
    k := random(n - 1) + 1;
    x := random(200);

    Writeln(n, ' ', k, ' ', x);
    Readln(ans);
    Writeln();

    Assign(infile, 'tests/0' + IntToStr(i));
    ReWrite(infile);
    writeln(infile, n, ' ', k, ' ', x);
    Close(infile);

    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(anfile);
    writeln(anfile, ans);
    Close(anfile);
  end;
end.
