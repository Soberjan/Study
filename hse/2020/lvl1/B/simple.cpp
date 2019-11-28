#include <iostream>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
#define ll long long

int n, k;
pair<ll, int> *a;

struct trio{
    ll x, y, z;
    trio(ll i, ll j, ll q) : x(i), y(j), z(q) {}
};
bool operator<(const trio& l, const trio& r) { return (l.x < r.x) || ((l.x == r.x) && (l.y < r.y)) || ((l.x == r.x) && (l.y == r.y) && (l.z < r.z)); }
map<trio, pair<ll, int>> cache;


pair<ll, int> f(ll i, ll j, int q){
    if (j <= 0)
        return {0, 0};
    trio t(i, j, q);
    if (cache.find(t) != cache.end())
        return cache[t];
    set<pair<ll, int>> s;
    if (n - i > j)
        s.insert({f(i+1, j, 0).X, 0});
    if ((n - i > j) && (q != 1))
        s.insert({a[i].Y + a[i+1].Y + f(i+1, j-1, 1).X, 1});
    if ((n - i > j) && (q != 2))
        s.insert({a[i].X + a[i+1].X + f(i+1, j-1, 2).X, 2});
    if ((q != 1) && (q != 2))
        s.insert({a[i].X +   a[i].Y + f(i+1, j-1, 3).X, 3});
    cache[t] = *(--s.end());
    return *(--s.end());
}

int main(){
 //  freopen("tests/03", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    a = new pair<ll, int>[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;

    pair<int, int> *b = new pair<int, int>[n];
    fill(b, b + n, make_pair(0, 0));
    for (int i = 0, q = 1, c = 0; q <= k; i++)
        switch (c = f(i, k - q + 1, c).Y){
            case 1: b[i].Y = b[i+1].Y = q++; break;
            case 2: b[i].X = b[i+1].X = q++; break;
            case 3: b[i].X = b[i].Y   = q++; break;
        }

    for (int i = 0; i < n; i++)
        cout << b[i].X << " " << b[i].Y << "\n";
    return 0;
}
