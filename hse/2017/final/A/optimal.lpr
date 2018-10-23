program optimal;

uses
  Math;

type
  localtime = record
    m, zone: shortint;
    h, days: longint;
  end;

var
  Result, place1, flight: localtime;

  function optimal(): localtime;
  var
    r_t: localtime;
  begin
    r_t.days := 0;
    r_t.h := place1.h + flight.h - place1.zone + flight.zone;
    if r_t.h < 0 then
    begin
      r_t.h += 24;
      r_t.days -= 1;
    end;

    r_t.h := ifthen(place1.m + flight.m >= 60, r_t.h + 1, r_t.h);
    r_t.m := ifthen(place1.m + flight.m >= 60, place1.m + flight.m -
      60, place1.m + flight.m);

    r_t.days := r_t.days + (r_t.h div 24);
    r_t.h := r_t.h mod 24;

    exit(r_t);
  end;

begin
  //assign(input, 'tests\10');
  //reset(input);

  readln(place1.h, place1.m);
  readln(flight.h, flight.m);
  readln(place1.zone, flight.zone);

  Result := optimal();
  Writeln(Result.h, ' ', Result.m, ' ', Result.days);
  readln();
end.
