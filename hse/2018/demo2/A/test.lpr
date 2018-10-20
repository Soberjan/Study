program test;

uses
  Math;

type
  Time = record
    h, m, s: byte;
  end;
const
  Nlim = 100000;
var
  a: array[1..NLIM] of Time;
  i, j, n: longint;

  function less(l, r: Time): boolean;
  begin
    exit((r.h < l.h) or ((r.h = l.h) and (r.m < l.m)) or
      ((r.h = l.h) and (r.m = l.m)) and (r.s <= l.s));
  end;

  function simple(): longint;
  var
    k, j: longint;
  begin
    k := 1;
    for j := 1 to n do
    begin
    if less(a[j - 1], a[j]) then
      k += 1;
    end;
    exit(k);
  end;

  function optimal(): longint;
  var
    k, j: longint;
  begin
    k := 1;
    for j := 1 to n do
    begin
    if a[j - 1].h * 3600 + a[j - 1].m * 60 + a[j - 1].s >= a[j].h *
      3600 + a[j].m * 60 + a[j].s then
      k := k + 1;
    end;
    exit(k);
  end;

begin

  for i := 1 to 10000 do
  begin
    n := NLIM - random(NLIM div 2);
    for j := 1 to n do
    begin
      a[j].h := random(24);
      a[j].m := random(59);
      a[j].s := random(59);
    end;
    if simple() <> optimal() then
    begin
      writeln('error!');
      optimal();
    end;

  end;
  writeln('done!');
  Readln();
end.

