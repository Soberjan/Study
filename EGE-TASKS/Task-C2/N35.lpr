program N35;
const
  N = 6;

var
  a: array[1..N] of integer;
  Max, Sum, i, k: integer;

begin
  for i:=1 to N do readln(A[i]);

  Sum:=a[1]+a[2]+a[3];
  Max:=Sum; k:=1;

  for i:=2 to N-2 do begin
    Sum:=Sum-a[i-1]+a[i+2];
    if Sum >Max then begin
      Max:=Sum;
      k:=i
    end
  end;

  for i:=k to k+2 do
    writeln('A[',i,']=',a[i])

end.



