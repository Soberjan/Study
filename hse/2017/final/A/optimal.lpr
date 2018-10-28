program optimal;

uses
  Math;


  procedure fix_hours(var h, d: longint);
  begin
    d += h div 24;
    h := h mod 24;
  end;

  procedure optimal();
  var
    hd, md, hf, mf, d, a, dd: longint;
  begin
    readln(hd, md);
    readln(hf, mf);
    readln(d, a);
    dd := 0;

    hd += 24 - d;
    dd -= 1;
    fix_hours(hd, dd);

    hd += hf + (md + mf) div 60;
    md := (md + mf) mod 60;
    fix_hours(hd, dd);

    hd += 24 + a;
    dd -= 1;
    fix_hours(hd, dd);

    Writeln(hd, ' ', md, ' ', dd);
  end;

begin
  //Assign(input, 'tests\00');
  //reset(input);

  optimal();

  readln();
end.
