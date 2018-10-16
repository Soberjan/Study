program optimal;
uses
  Math;

type
  return_time = record
    h3, m3, days: integer;
  end;



var
  h1, m1, h2, m2, d, a: integer;
  result: return_time;

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
  readln(h1, m1);
  readln(h2, m2);
  readln(d, a);


  result := optimal();
  Writeln(result.h3, ' ', result.m3, ' ', result.days);
  readln();
end.

