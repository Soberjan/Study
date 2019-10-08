#include <iostream>
using namespace std;

int l, r, a;
int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> l >> r >> a;

    long long s = 0;
    for (int i = l; i <= r - a; i++)
        s += (r - i) / a;

    cout << s;
    return 0;
}
