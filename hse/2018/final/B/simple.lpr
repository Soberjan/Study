program simple;

uses
  Math;

type
  Guest = record
    a, b, i: longint;
  end;
  CheckProperty = function(a, m: Guest): boolean;
var
  a: array[1..100000] of Guest;
  n, i: longint;

  function CompareById(a, m: Guest): boolean;
  begin
    if a.i < m.i then
      exit(True)
    else
      exit(False);
  end;

  function CompareByA(a, m: Guest): boolean;
  begin
    if (a.a < m.a) or ((a.a = m.a) and (a.b < m.b)) then
      exit(True)
    else
      exit(False);
  end;

  procedure swap(var a, b: Guest);
  var
    t: Guest;
  begin
    t := a;
    a := b;
    b := t;
  end;

  function partition(f: CheckProperty; lo, hi: longint): longint;
  var
    pivot: Guest;
    i, j: longint;
  begin
    pivot := a[hi];
    i := lo;
    for j := lo to hi - 1 do
      if f(a[j], pivot) then
      begin
        swap(a[i], a[j]);
        i := i + 1;
      end;
    swap(a[i], a[hi]);
    exit(i);
  end;

  procedure quicksort(f: CheckProperty; lo, hi: longint);
  var
    p: longint;
  begin
    if lo < hi then
    begin
      p := partition(f, lo, hi);
      quicksort(f, lo, p - 1);
      quicksort(f, p + 1, hi);
    end;
  end;

  procedure Simple();
  var
    i, curr: longint;
  begin
    quicksort(@CompareByA, 1, n);

    curr := a[1].b;
    for i := 2 to n do
    begin
      if (a[i].b <= curr) then
      begin
        a[i].a := -1;
        a[i].b := -1;
      end;

      if (a[i].b > curr) then
      begin
        a[i].a := max(a[i].a, curr + 1);
        curr := a[i].b;
      end;
    end;

    quicksort(@CompareById, 1, n);
  end;

begin
  //Assign(input, 'tests\00');
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

