#include <iostream>
#include <stdio.h>
using namespace std;

unsigned long long m, x, y, w, h;


int main()
{
    //freopen("tests/03", "r", stdin);
    cin >> m >> x >> y >> w >> h;
    unsigned long long r1 = x % m;
    unsigned long long r2 = y % m;
    unsigned long long wc = (w - r1) % m == 0 ? (w - r1) / m : (w - r1) / m + 1;
    unsigned long long hc = (h - r2) % m == 0 ? (h - r2) / m : (h - r2) / m + 1;
    wc = r1 == 0 ? wc : wc + 1;
    hc = r2 == 0 ? hc : hc + 1;
    cout << wc * hc;
    return 0;
}
