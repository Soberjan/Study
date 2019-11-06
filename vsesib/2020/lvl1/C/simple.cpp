#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define X first
#define Y second

int n;
map<int, vector<int>> g;

inline ll sqr(ll a){
    return a * a;
}

int F(int x, int y){
    int m = 0;
    for (int z : g[x])
        if (z != y)
            m = max(F(z, x) + 1, m);
    return m;
}

ll G(int x){
    ll s = 0;
    for (int y : g[x])
        s += sqr(F(y, x) + 1);
    return s;
}

int main(){
//    freopen("tests/00", "r", stdin);
    cin >> n;

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    pair<ll, int> m = {G(0), 0};
    for (int i = 1; i < n; i++){
        pair<ll, int> t = {G(i), i};
        if (t < m)
            m = t;
    }

    cout << m.X << " " << m.Y + 1;
    return 0;
}
