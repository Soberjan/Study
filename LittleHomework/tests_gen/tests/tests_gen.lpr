program tests_gen;

const
  N = 6;

var
  f, g: TextFile;
  a: array [1..N] of integer;
  b, i, j, z: integer;
  c, d: string;
begin

  Writeln('How much tests should I create?');
  Readln(z);

  for j := 1 to z do
  begin
    Writeln('Enter the file name');
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
    Close(f);

    Writeln('Enter the right answer and files name');
    Readln(b);
    Readln(d);
    Assign(g, d);
    ReWrite(g);
    Write(g, b);
    Close(g);
  end;
  Readln();

end.
