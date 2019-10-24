#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int n, a, b;

int main()
{
    //freopen("tests/03", "r", stdin);
    cin >> n >> a >> b;
    ll q = 0;
    for (int i = 0; i * 3 <= b * 3; i++)
        for (int j = 0; j <= a * 2; j++)
            q += (i * 3 + j * 2 == n);
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
