#include <iostream>
#include <cmath>
using namespace std;

long long m, x, y, w, h;

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> m >> x >> y >> w >> h;
    long long x2 = x + w, y2 = y + h;
    long long kw = floor((float)x2 / m) - ceil((float)x / m);
    kw = x % m > 0 ? kw + 1 : kw;
    kw = x2 % m > 0 ? kw + 1 : kw;
    long long kh = floor((float)y2 / m) - ceil((float)y / m);
    kh = y % m > 0 ? kh + 1 : kh;
    kh = y2 % m > 0 ? kh + 1 : kh;
    cout << kh * kw;
    return 0;
}
