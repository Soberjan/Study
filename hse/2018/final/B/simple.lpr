program simple;

type
  Guest = record
    a, b, i: longint;
  end;
  CheckProperty = function(a, m: Guest): boolean;

const
  NLIM = 100000;

var
  a: array[1..100000] of Guest;
  n, i: longint;

  function CheckId(a, m: Guest): boolean;
  begin
    if a.i < m.i then
      exit(true)
    else
      exit(false);
  end;

  function CheckA(a, m: Guest): boolean;
  begin
    if (a.a < m.a) or ((a.a = m.a) and (a.b < m.b)) then
      exit(true)
    else
      exit(false);
  end;

  procedure SortArray(f: CheckProperty);
  var
    t: Guest;
    i, j, m: longint;
  begin
    for i := 1 to n - 1 do
    begin
      m := i;
      for j := i + 1 to n do
        if f(a[j], a[m]) then
          m := j;
      t := a[m];
      a[m] := a[i];
      a[i] := t;
    end;
  end;

  procedure Simple();
  var
    i, max: longint;
  begin
    SortArray(@CheckA);

    max := a[1].b;
    for i := 2 to n do
    begin
      if (a[i].b <= max) then
      begin
        a[i].a := -1;
        a[i].b := -1;
      end;
      if (a[i].b > max) and (a[i].a <= max) then
        begin
          a[i].a := max + 1;
          max := a[i].b;
        end
      else if (a[i].a >= max) then
        max := a[i].b;
    end;

    SortArray(@CheckId);
  end;

begin
  //Assign(input, 'check\14');
  //reset(input);

  Readln(n);
  for i := 1 to n do
  begin
    Readln(a[i].a, a[i].b);
    a[i].i := i;
  end;
  simple();
  for i := 1 to n do
    Writeln(a[i].a, ' ', a[i].b);

end.



