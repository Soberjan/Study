#include <iostream>
#include <set>
#include <map>
#include <list>
using namespace std;

int n, k;
map<int, list<int>> l;
map<int, set<int>> s;
int *p;

void f(int i, int j){
    for (int x : l[i])
        p[x] = j;
    l[j].splice(l[j].end(), l[i]);
    s[j].insert(s[i].begin(), s[i].end());
    s.erase(i), l.erase(i);
}

int main(){
    //freopen("tests/02", "r", stdin);
    cin >> n >> k;
    p = new int[n+1];
    for (int i = 0; i <= n; i++)
        p[i] = i, l[i].push_back(i);
    for (int q = 0; q < k; q++){
        int a, b;
        char c;
        cin >> c >> a >> b;
        int i = p[a], j = p[b];
        if (c == '+')
            l[i].size() < l[j].size() ? f(i, j) : f(j, i);
        if (c == '-')
            s[i].insert(j), s[j].insert(i);
        if (c == '?')
            cout << ( (i == j) ? "+\n" : ((s[i].find(j) != s[i].end()) ? "-\n" : "?\n") );
    }
    return 0;
}
