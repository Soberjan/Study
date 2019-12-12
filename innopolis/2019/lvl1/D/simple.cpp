#include <iostream>
#include <set>
#include <map>
using namespace std;
#define ll long long
#define X first
#define Y second

const ll INF = 1e17;
int n, s, v;
int *a;

struct trio{int i, j, q; };
map<trio, ll> cache;
ll idx(const trio& l){ return l.i * (v+1) * (s+1) + l.j * s + l.q; }
bool operator<(const trio& l, const trio& r){ return idx(l) < idx(r); }

ll f(int i, int j, int q);
pair<ll, int> g(int i, int j, int h){
    if (j == 0)
        return {0, 0};
    pair<ll, int> m = {INF, INF};
    for (int q = max(0, j - (n - i - 1) * v); q <= min(j, v); q++)
        m = min(m, {h * a[i] * q + f(i + 1, j - q, q), q});
    return m;
}
ll f(int i, int j, int q) {
    trio t{i, j, q};
    return (cache.count(t) == 0 ? cache[t] = g(i, j, q).X : cache[t]);
}

int main(){
    freopen("tests/00", "r", stdin);
    cin >> n >> s >> v;
    a = new int[n+1];
    for (int i = 1; i < n; i++)
        cin >> a[i];

    for (int i = 0, j = s, h = 0; i < n; i++, j -= h)
        cout << (h = g(i,j,h).Y) << " ";

    return 0;
}
