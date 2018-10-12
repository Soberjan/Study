program test;

uses
  Math;

type
  Time = record
    h, m, s: integer;
  end;
const
  Nlim = 15;
var
  a: array[1..NLIM] of Time;
  i, j, n, o_res, s_res : integer;

  function less(r, l: Time): boolean;
  begin
    exit((r.h < l.h) or ((r.h = l.h) and (r.m < l.m)) or
      ((r.h = l.h) and (r.m = l.m)) and (r.s <= l.s));
  end;

  function simple(): integer;
  var
    k : integer;
  begin
    k := 1;
    if less(a[j], a[j - 1]) then
      k += 1;
    exit(k);
  end;

  function optimal(): integer;
  var
    k : integer;
  begin
    k := 1;
    if a[j - 1].h * 3600 + a[j - 1].m * 60 + a[j - 1].s >= a[j].h *
      3600 + a[j].m * 60 + a[j].s then
      k := k + 1;
    exit(k);
  end;

begin

  for i := 1 to 10000 do
  begin
    n := NLIM - random(NLIM div 2);
    a[1].h := random(24);
    a[1].m := random(59);
    a[1].s := random(59);
    for j := 2 to n do
    begin
      a[j].h := random(24);
      a[j].m := random(59);
      a[j].s := random(59);
    end;
    o_res := optimal();
    s_res := simple();
    if s_res <> o_res then
      begin
      writeln('error!');
      optimal();
      end;

  end;
  writeln('done!');
  Readln();
end.


