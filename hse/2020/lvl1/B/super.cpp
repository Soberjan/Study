#include <iostream>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
#define ll long long

int n, k;
pair<int, int> *a;

struct trio{int i, j, h; };
ll idx(const trio& t){ return t.i*(k+1)*4 + t.j*4 + t.h; }
bool operator<(const trio& l, const trio& r) {return idx(l) < idx(r); }
map<trio, ll> cache;

pair<ll, int> g(int i, int j, int h);
ll f(int i, int j, int h){
    trio t {i, j, h};
    return cache.count(t) > 0 ? cache[t] : cache[t] = g(i, j, h).X;
}
pair<ll, int> g(int i, int j, int h){
//    cout << i << " " << j << " " << h << endl;
    if (j == 0)
        return {0, 0};
    set<pair<ll, int>> s;
    if (n - i > j)
        s.insert({f(i+1, j  , 0)                    , 0});
    if ((n - i > j) && (h != 1))
        s.insert({f(i+1, j-1, 1) + a[i].Y + a[i+1].Y, 1});
    if ((n - i > j) && (h != 2))
        s.insert({f(i+1, j-1, 2) + a[i].X + a[i+1].X, 2});
    if ((h != 1) && (h != 2))
        s.insert({f(i+1, j-1, 3) + a[i].X + a[i]  .Y, 3});
    return s.size() > 0 ? *(--s.end()) : (pair<ll, int>) {0, 0};
}

int main(){
//    freopen("tests/10", "r", stdin);
    cin >> n >> k;
    a = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;

    ll *c = new ll[(n+1)*(k+1)*4]{0};
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= k; j++)
            for (int h = 0; h < 4; h++)
                c[(i)*(k+1)*4+(j)*4+(h)] = g(i, j, h).X;

    return 0;
}

