program simple;

uses
  Math;

type
  localtime = record
    h: longint;
    m, days, zone: shortint;
  end;


var
  Result, place1, flight: localtime;

  function ToUtc(time: localtime): localtime;
  var
    i: byte;
  begin
    if time.zone <> 0 then
    begin
      if time.zone < 0 then
        for i := 1 to abs(time.zone) do
          time.h += 1;
      if time.zone > 0 then
        for i := 1 to time.zone do
          time.h -= 1;
    end;
    exit(time);
  end;

  function ToLocal(time: localtime): localtime;
  var
    i: byte;
  begin
    if flight.zone <> 0 then
    begin
      if flight.zone < 0 then
        for i := abs(flight.zone) - 1 downto 0 do
          time.h -= 1;
      if flight.zone > 0 then
        for i := flight.zone - 1 downto 0 do
          time.h += 1;
    end;
    exit(time);
  end;

  function FlightTime(time: localtime): localtime;
  var
    i: byte;
  begin
    if flight.h <> 0 then
    begin
      for i := flight.h - 1 downto 0 do
      begin
        time.h += 1;
        if time.h = 24 then
        begin
          time.days += 1;
          time.h := 0;
        end;
      end;
      exit(time);
    end;
  end;

  function simple(): localtime;
  var
    r_t: localtime;
  begin
    r_t := ToUtc(place1);
    r_t := FlightTime(r_t);
    r_t.h := ifthen(place1.m + flight.m >= 60, r_t.h + 1, r_t.h);
    r_t.m := ifthen(place1.m + flight.m >= 60, place1.m + flight.m -
      60, place1.m + flight.m);
    r_t := ToLocal(r_t);
    while r_t.h >= 24 do
    begin
      r_t.h -= 24;
      r_t.days += 1;
    end;
    if r_t.h < 0 then
    begin
      r_t.days -= 1;
      r_t.h := 24 + r_t.h;
    end;
    exit(r_t);
  end;

begin

  Readln(place1.h, place1.m);
  Readln(flight.h, flight.m);
  Readln(place1.zone, flight.zone);

  Result := simple();
  Writeln(Result.h, ' ', Result.m, ' ', Result.days);

end.
