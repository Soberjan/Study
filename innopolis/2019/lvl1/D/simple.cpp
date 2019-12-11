#include <iostream>
#include <set>
#include <map>
using namespace std;
#define ll long long
#define X first
#define Y second

int n, s, v;
int *a;

struct trio{int i, j, q; };
map<trio, ll> cache;
ll idx(const trio& l){ return l.i * (v+1) * (s+1) + l.j * s + l.q; }
bool operator<(const trio& l, const trio& r){ return idx(l) < idx(r); }

ll f(int i, int j, int q);
pair<ll, int> g(int i, int j, int q){
//    cout << i << " " << j << " " << q << "\n";
    if (j == 0)
        return {0, 0};
    set<pair<ll, int>> m;
    for (int k = 0; (k <= j) && (k <= v); k++)
        if ( j - k <= v * (n - i) )
            m.insert({q * k * a[i-1] + f(i+1, j-k, k), k});
    return *m.begin();
}
ll f(int i, int j, int q) {
    trio t{i, j, q};
    return (cache.count(t) == 0 ? cache[t] = g(i, j, q).X : cache[t]);
}

int main(){
    freopen("tests/01", "r", stdin);
    cin >> n >> s >> v;
    a = new int[n+1];
    a[0] = a[n] = 0;
    for (int i = 1; i < n; i++)
        cin >> a[i];

    int *b = new int[n];
    for (int i = 1, j = s, q = 0; i <= n; i++){
        b[i-1] = q = g(i, j, q).Y;
        j -= q;
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    return 0;
}
