program simple;
uses
  Math;

type
  return_time = record
    h3, m3, days: integer;
  end;

var
  h1, m1, h2, m2, d, a: integer;
  ans: return_time;

function simple(): return_time;
var
  gr_time, i: integer;
  r_t: return_time;

begin
  gr_time := h1 - d;
  gr_time += h2;

  gr_time := ifthen(m1 + m2 >= 60, gr_time + 1, gr_time);
  r_t.m3 := ifthen(m1 + m2 >= 60, m1 + m2 - 60, m1 + m2);

  r_t.h3 := gr_time + a;
  r_t.days := r_t.h3 div 24;
  r_t.h3 := r_t.h3 mod 24;        7

  exit(r_t);
end;

begin
  Readln(h1, m1);
  Readln(h2, m2);
  Readln(d, a);

  ans := simple();
  Writeln(ans.h3, ' ', ans.m3, ' ', ans.days);

end.

