#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define X first
#define Y second

ll a, b, c, d, N, n;

int main(){
    //freopen("tests/01", "r", stdin);
    cin >> a >> b >> c >> d >> N >> n;

    vector<pair<ll, ll>> v;
    for (ll i = 1; i <= N; i++)
        for (ll j = 1; (j < N) && (j * d < c * i); j++)
            if ( (__gcd(i, j) == 1) && (j * b > a * i) && (j * d < c * i) && ((int)v.size() < n) )
                v.push_back({j, i});

    cout << v.size() << endl;
    for (pair<ll, ll> x : v)
        cout << x.X << " " << x.Y << endl;
    return 0;
}
