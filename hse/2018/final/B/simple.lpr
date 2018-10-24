program simple;

type
  Guest = record
    a, b, i: longint;
  end;

const
  NLIM = 10000;
var
  a: array[1..NLIM] of Guest;
  res: Guest;
  n, i: longint;

  procedure SortArray();
  var
    t: Guest;
    i, j, m: longint;
  begin
    for i := 1 to n - 1 do
    begin
      m := i;
      for j := i + 1 to n do
        if a[j].a < a[m].a then
          m := j;
      t := a[m];
      a[m] := a[i];
      a[i] := t;
    end;
  end;

  procedure SeekGuestTime();
  var
    i, ih: longint;
  begin
    for i := 2 to n do
    begin
      ih := i - 1;
      while a[ih].a = -1 do
        ih -= 1;

      if (a[i].b > a[ih].b) and (a[i].a <= a[ih].b) then
        a[i].a := a[ih].b + 1;

      if (a[i].b <= a[ih].b) then
      begin
        a[i].a := -1;
        a[i].b := -1;
      end;
    end;
  end;

  procedure SortBack();
  var
    t: Guest;
    i, j, m: longint;
  begin
    for i := 1 to n - 1 do
    begin
      m := i;
      for j := i + 1 to n do
        if a[j].i < a[m].i then
          m := j;
      t := a[m];
      a[m] := a[i];
      a[i] := t;
    end;
  end;

  procedure Simple();
  begin
    SortArray();
    SeekGuestTime();
    SortBack();
  end;

begin
  //Assign(input, 'tests\03');
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



