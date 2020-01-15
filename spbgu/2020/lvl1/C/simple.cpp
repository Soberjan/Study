#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ll long long

int k, n, m, u, v;
vector<pair<int, int>> *r;
int l;
set<int> z;

set<pair<int, int>> cache;
int f(int i, int j){
    //cout << i << " " << j << "\n";
    if ((j < 0) || (cache.find(mp(i, j)) != cache.end()))
        return -1;
    if (i == v)
        return 0;
    cache.insert(mp(i, j));

    int m1 = -1;
    for (auto x : r[i]){
        int t = f(x.X, j - x.Y);
        if ((m1 == -1) && (t == -1))
            m1 = t;
        if ((m1 == -1) && (t != -1))
            m1 = t;
        if ((m1 != -1) && (t == -1))
            m1 = m1;
        if ((m1 != -1) && (t != -1))
            m1 = min(m1, t);
    }
    int m2 = z.find(i) != z.end() ? f(i, k) : m1;
    m2 = m2 != -1 ? m2 + 1 : -1;

    if ((m1 == -1) && (m2 == -1))
        return -1;
    if ((m1 == -1) && (m2 != -1))
        return m2;
    if ((m1 != -1) && (m2 == -1))
        return m1;
    if ((m1 != -1) && (m2 != -1))
        return min(m1, m2);
}

int main(){
    freopen("tests/03", "r", stdin);
    cin >> k >> n >> m >> u >> v;
    r = new vector<pair<int, int>>[10000];
    for (int i = 0; i < m; i++){
        int b, e, s;
        cin >> b >> e >> s;
        r[b].push_back({e, s});
        r[e].push_back({b, s});
    }
    cin >> l;
    for (int i = 0; i < l; i++){
        int a;
        cin >> a;
        z.insert(a);
    }

    cout << f(u, k);

    return 0;
}
