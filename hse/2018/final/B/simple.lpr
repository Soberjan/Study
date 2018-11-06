program simple;

uses
  Math;

type
  Guest = record
    a, b, i: longint;
  end;
  //CheckProperty = function(a, m: Guest): boolean;
  CheckProperty = function(a: Guest): longint;
var
  a: array[1..100000] of Guest;
  n, i: longint;

  //function CompareById(a, m: Guest): boolean;
  //begin
  //  if a.i < m.i then
  //    exit(True)
  //  else
  //    exit(False);
  //end;
  //
  //function CompareByA(a, m: Guest): boolean;
  //begin
  //  if (a.a < m.a) or ((a.a = m.a) and (a.b < m.b)) then
  //    exit(True)
  //  else
  //    exit(False);
  //end;
  //
  //procedure SortArray(f: CheckProperty);
  //var
  //  t: Guest;
  //  i, j, m: longint;
  //begin
  //  for i := 1 to n - 1 do
  //  begin
  //    m := i;
  //    for j := i + 1 to n do
  //      if f(a[j], a[m]) then
  //        m := j;
  //    t := a[m];
  //    a[m] := a[i];
  //    a[i] := t;
  //  end;
  //end;

  function CompareById(a: Guest): longint;
  begin
    exit(a.i);
  end;

  function CompareByA(a: Guest): longint;
  begin
    exit(a.a);
  end;

  procedure swap(var a, b: longint);
  var
    t: longint;
  begin
    t := a;
    a := b;
    b := t;
  end;

  function partition(f: CheckProperty; lo, hi: longint): longint;
  var
    pivot, i, j: longint;
  begin
    pivot := f(a[hi]);
    i := lo;
    for j := lo to hi - 1 do
      if f(a[j]) <= pivot then
      begin
        swap(f(a[i]), f(a[j]));
        i := i + 1;
      end;
    swap(f(a[i]), f(a[hi]));
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
    //SortArray(@CompareByA);
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
    //SortArray(@CompareById);
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

