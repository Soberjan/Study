program tests_gen;

uses
  SysUtils;

type
  PrintStuff = record
    c: char;
    a, b: longint;
  end;

var
  infile, anfile: TextFile;
  a, ans: array[1..30] of integer;
  b: array[1..30] of PrintStuff;
  i, j, k, n, q, help: longint;

begin
  Randomize();
  for i := 6 to 8 do
  begin
    n := random(20) + 2;
    q := random(10) + 1;
    for j := 1 to n do
      a[j] := random(5);

    k := 0;
    for j := 1 to q do
    begin
      help := random(10);
      if help <= 3 then
      begin
        b[j].c := '!';
        b[j].b := random(n) + 1;
        b[j].a := random(b[j].b) + 1;
      end
      else
      begin
        b[j].c := '?';
        b[j].b := random(n) + 1;
        b[j].a := random(b[j].a) + 1;
        k += 1;
      end;

    end;

    Writeln(n, ' ', q);
    for j := 1 to n do
      Write(a[j], ' ');
    Writeln();
    for j := 1 to q do
    begin
      Writeln(b[j].c, ' ', b[j].a, ' ', b[j].b);
    end;

    for j := 1 to k do
      Readln(ans[j]);

    Writeln();

    Assign(infile, 'tests/0' + IntToStr(i));
    ReWrite(infile);
    Writeln(infile, n, ' ', q);
    for j := 1 to n do
      Write(infile, a[j], ' ');
    Writeln(infile);
    for j := 1 to q do
    begin
      Writeln(infile, b[j].c, ' ', b[j].a, ' ', b[j].b);
    end;
    Close(infile);

    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(anfile);
    for j := 1 to k do
      writeln(anfile, ans[j]);
    Close(anfile);
  end;
end.
