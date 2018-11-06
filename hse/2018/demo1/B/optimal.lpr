program optimal;
uses
  Math;

var
  a : array[1..200000] of longint;
  i, n, k : longint;

  function optimal(): longint;
  var
    i, j, m, t, noncomf: longint;
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
    noncomf := a[n - k] - a[1];
    for i := 1 to k + 1 do
      noncomf := min(noncomf, a[n - k - 1 + i] - a[i]);
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
