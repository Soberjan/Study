program test;
uses
  Math;

type
  return_time = record
    h3, m3, days: integer;
  end;

var
  i, h1, m1, h2, m2, d, a: integer;
  simple_res, optimal_res: return_time;

function simple(): return_time;
var
  gr_time: integer;
  r_t: return_time;
begin
  gr_time := h1 - d;
  gr_time += h2;

  gr_time := ifthen(m1 + m2 >= 60, gr_time + 1, gr_time);
  r_t.m3 := ifthen(m1 + m2 >= 60, m1 + m2 - 60, m1 + m2);

  r_t.h3 := gr_time + a;
  r_t.days := r_t.h3 div 24;
  r_t.h3 := r_t.h3 mod 24;

  exit(r_t);
end;

function optimal(): return_time;
var
  r_t: return_time;

begin
  r_t.h3 := h1 + h2 - d + a;

  r_t.h3 := ifthen(m1 + m2 >= 60, r_t.h3 + 1, r_t.h3);
  r_t.m3 := ifthen(m1 + m2 >= 60, m1 + m2 - 60, m1 + m2);

  r_t.days := r_t.h3 div 24;
  r_t.h3 := r_t.h3 mod 24;

  exit(r_t);
end;

begin

  for i := 1 to 1000000 do
  begin
    h1 := random(23);
    h2 := random(23);
    m1 := random(59);
    m2 := random(59);
    d := random(25) - 11;
    a := random(25) - 11;

    simple_res := simple();
    optimal_res := optimal();
    if (simple_res.h3 <> optimal_res.h3) or (simple_res.m3 <> optimal_res.m3) or (simple_res.days <> optimal_res.days) then
      writeln('error!');
  end;
  writeln('done!');
  Readln();
end.


