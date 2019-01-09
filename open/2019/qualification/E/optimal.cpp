#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;

#define X first
#define Y second

int n, m;
pair<int, int> p[3000000];

list<int> optimal(){
    list<int> ans;
    sort(p, p + m);
    map <int, set<int> > g; int num = 1; set<int> tmp;
    for (int i = 0; i < m; i++)
        if (p[i].X != num){
            set_union(tmp.begin(), tmp.end(), g[num].begin(), g[num].end(), inserter(g[num], g[num].begin()));
            tmp.clear();
            num = p[i].X;
        }
        else{
            tmp.insert(p[i].Y);
            g[p[i].Y].insert(p[i].X);
        }

    int* q = new int[10 * n], *c = new int[n];
    for (int i = 1; i <= n; i++){
        map <int, set<int> > tg = g;
        memset(c, 0, 4 * n);
        c[i] = 3;
        while (!map.empty()){
            tg.
        }
    }

    return ans;
}

int main()
{
    //freopen("tests/03", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i].X >> p[i].Y;

    list<int> c = optimal();

    cout << c.size();
    for (list<int>::iterator it = c.begin(); it != c.end(); ++it)
        cout << *it << " ";

    return 0;
}
