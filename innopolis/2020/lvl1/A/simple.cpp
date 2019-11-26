#include <iostream>
using namespace std;
#define ll long long

ll a, b, x;

int main(){
   // freopen("tests/02", "r", stdin);
    cin >> a >> b >> x;

    ll m = 0;
    for (ll k1 = 0; k1 <= 1000; k1++)
        for (ll k2 = 0; k2 <= 1000; k2++)
            if ((a * k1 * (100 - x) == b * k2 * x) && (a * k1 + b * k2 <= 1000))
                m = max(m, k1 * a + k2 * b);
    cout << m;

    return 0;
}
