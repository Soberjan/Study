#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second
#define ll long long

ll a, b, c, d, N, n;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> a >> b >> c >> d >> N >> n;

    vector<pair<ll, ll>> ans;
    for (ll f = 1; (f <= N) && ((ll)ans.size() < n); f++)
        for (ll e = 1; (e <= N) && ((ll)ans.size() < n) && (e * d < f * c); e++)
            if ( (__gcd(e, f) == 1) && (e * b > f * a))
                ans.push_back({e, f});

    cout << ans.size() << "\n";
    for (auto p : ans)
        cout << p.X << " " << p.Y << "\n";
    return 0;
}
