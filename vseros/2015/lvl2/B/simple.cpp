#include <iostream>
using namespace std;
#define ll long long

ll n, a, b, c, d;

ll f(ll i, ll j, ll k){
    k = k < 0 ? 0 : k;
    return i * b + j * d + k;
}

int main(){
   // freopen("tests/01", "r", stdin);
    cin >> n >> a >> b >> c >> d;

    ll s = n % (1 * a + 2 * c);
    for (int i = 0; i * a <= n + a; i++)
        for (int j = 0; (i * a + j * c) <= n + a + c; j++)
            s = min(s, f(i, j, n - i * a - j * c));

    cout << s;
    return 0;
}
