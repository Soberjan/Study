program optimal;
uses
  Math;

var
  a : array[1..200000] of longint;
  i, n, k : longint;

  function optimal(): longint;
  var
    i, j, m, t, i1, i2, noncomf: longint;
  begin
    if (n - k <= 1) then
      exit(0);
    m := 0;
    t := 0;
    for i := 1 to n do
    begin
      m := i;
      for j := i + 1 to n do
        if a[j] < a[m] then
          m := j;
      t := a[m];
      a[m] := a[i];
      a[i] := t;
    end;
    i2 := n - k - 1;
    noncomf := a[n] - a[1];
    for i1 := 1 to k do
    begin
      i2 += 1;
      noncomf := min(noncomf, a[i2] - a[i1]);
    end;
    noncomf := min(noncomf, a[n] - a[k + 1]);
    exit(noncomf);
  end;    
begin
  //assign(input, 'tests\03');
  //reset(input);
  Read(n, k);
  for i := 1 to n do
    Read(a[i]);
  Writeln(optimal());

  Readln();

end.
