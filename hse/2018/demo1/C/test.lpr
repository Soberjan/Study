program test;

uses
  Math;

const
  NLIM = 10;

var
  a: array[1..NLIM] of integer;
  i, j, n : integer;

  function simple(): integer;
  begin
  end;

  function optimal(): integer;
  
  begin
  end;

begin

  for i := 1 to 10000 do
  begin
    n := NLIM - random(NLIM div 2);
    for j := 1 to n do
      a[j] := random(30) + 1;
    if simple() <> optimal() then
      writeln('error!');

  end;
  writeln('done!');
  Readln();
end.


