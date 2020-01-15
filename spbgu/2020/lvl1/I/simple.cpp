#include <iostream>
#include <map>
#include <set>
#include <bitset>
#include <deque>
using namespace std;

int n, m;
set<int> *g;

int main(){
//    freopen("tests/00", "r", stdin);
    cin >> n >> m;
    g = new set<int>[n];
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, (int)g[i].size());


    return 0;
}
