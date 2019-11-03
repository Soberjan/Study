#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int n, a, b;

int main()
{
    //freopen("tests/04", "r", stdin);
    cin >> n >> a >> b;
    ll q = 0;
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            if (i * 2 + j * 3 == n)
                q++;
    ll p = (a + 1) * (b + 1);
    if (q == 0)
        cout << 0;
    else if (q == p)
        cout << 1;
    else{
        int g = __gcd(q, p);
        p /= g;
        q /= g;
        cout << q << "/" << p;
    }
    return 0;
}
