program tests_gen;

const N = 6;

var
  f, g : Text;
  a : array [1..N] of integer;
  b, i : integer;
  c, d : string;
begin

  Writeln('Enter the file name. USE ".exe!" Dont forget to enter path.');
  Readln(c);
  Assign(f, c);
  ReWrite(f);

  Randomize();
  for i := 1 to N do
  begin
    a[i] := random(9);
    Write(a[i], ' ');
    Write(f, a[i], ' ');
  end;

  Writeln('Enter the right answer and files name');
  Readln(b);
  Readln(d);
  Assign(g, d);
  ReWrite(g);
  Write(g, b);

  Readln();

end.

