#include <iostream>
using namespace std;

int l, r, a;

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> l >> r >> a;
    long long k = (r - l) / a, q = (r - l) % a;
    cout << (long long) k * (q + 1)  + a * k * (k - 1) / 2;
    return 0;
}
