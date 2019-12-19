#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#define ll long long
#define X first
#define Y second

ll a, b, c, d, N, n;

int main(){
 //   freopen("tests/02", "r", stdin);
    cin >> a >> b >> c >> d >> N >> n;

    list<pair<ll, ll>> m;
    for (ll i = 1; i <= N; i++)
        for (ll j = 1; j <= N; j++)
            if ( (__gcd(i, j) == 1) && (j * b > a * i) && (j * d < c * i) && ((ll)m.size() < n) )
                m.push_back({j, i});

    cout << m.size() << endl;
    for (pair<ll, ll> x : m)
        cout << x.X << " " << x.Y << endl;

    return 0;
}
