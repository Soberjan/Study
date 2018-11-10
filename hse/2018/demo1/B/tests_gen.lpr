program tests_gen;

uses
  SysUtils;

const
  NLIM = 30;
  VLIM = 35;
var
  infile, anfile: TextFile;
  a: array [1..NLIM] of longint;
  ans, i, j, h, t, maxnum, n, k: longint;


begin
  Randomize();
  for i := 2 to 5 do
  begin
    n := random(15) + 1;
    k := random(n); 
    for j := 1 to n do
      a[j] := random(VLIM) - 15;

    Assign(infile, 'tests/0' + IntToStr(i));
    ReWrite(infile);
    writeln(infile, n, ' ', k);
    for j := 1 to n do
      write(infile, a[j], ' ');
    Close(infile);

    for j := 1 to n - 1 do
    begin
      maxnum := j;
      for h := j + 1 to n do
        if a[h] > a[maxnum] then
          maxnum := h;
      t := a[maxnum];
      a[maxnum] := a[j];
      a[j] := t;
    end;

    Writeln(n, ' ', k);
    for j := 1 to n do
      Write(a[j], ' ');
    Writeln();
    Readln(ans);

    Assign(anfile, 'tests/0' + IntToStr(i) + '.a');
    ReWrite(anfile);
    writeln(anfile, ans);
    Close(anfile);
  end;
end.
