program simple;

var
  a, b: array[1..100000] of longint;
  max, max2, max3, n, i, j, h, s: longint;

begin
  //Assign(input, 'tests\04');
  //reset(input);

  Readln(n);
  s := 0;

  for i := 1 to n do
    Read(a[i]);

  //for i := 1 to n do
  //begin
  //  if a[i] > a[max2] then
  //  begin
  //    for j := i to n do
  //      if a[j] >= a[i] then
  //      begin
  //        for h := i to j do
  //          b[h] := a[i] - a[h];
  //        i := j;
  //      end;
  //   end;
  //end;

  max := 0;
  max2 := 0;
  max3 := 0;
  i := 1;
  repeat
    if a[i] > a[max] then
    begin
      max :=i;
      for j := i to n do
        if a[j] >= a[i] then
        begin
          for h := i to j do
            b[h] := a[i] - a[h];
          i := j;
        end;
     end
    else
     i += 1;
  until i = n;

  //for i := 1 to n do
  //begin
  //  if a[i] >= a[max2] then
  //  begin
  //    max1 := max2;
  //    max2 := i;
  //    max3 := i + 1;
  //    for j := max1 + 1 to max2 - 1 do
  //      b[j] := a[max1] - a[j];
  //
  //    //for j := i + 1 to n do
  //    //begin
  //    //  if a[j] >= a[i] then
  //    //    break;
  //    //  if j = n then
  //    //    max2 := max3;
  //    //end;
  //  end;
  //  if (a[i] < a[max2]) and (a[i] >= a[max3]) then
  //  begin
  //    max3 := i;
  //    for j := max2 + 1 to max3 - 1 do
  //      b[j] := a[max3] - a[j];
  //  end;
  //end;
  for i := 1 to n do
    s += b[i];

  Writeln(s);

end.
