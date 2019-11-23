#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define X first
#define Y second

int n, k;
vector<int> a, b;

ll f(int i, int j, int h);
pair<ll, int> g(int i, int j, int h) {
    set<pair<ll, int>> s;
    if (n - i > j)
        s.insert({f(i + 1, j, 0), 0});
    if ((n - i > j) && (h != 1))
        s.insert({b[i] + b[i+1] + f(i + 1, j - 1, 1), 1});
    if ((n - i > j) && (h != 2))
        s.insert({a[i] + a[i+1] + f(i + 1, j - 1, 3), 2});
    if ((h != 1) && (h != 2))
        s.insert({a[i] + b[i]   + f(i + 1, j - 1, 3), 3});
    return *(--s.end());
}
ll f(int i, int j, int h) { return j > 0 ? g(i, j, h).X : 0; }

int main(){
    freopen("tests/03", "r", stdin);
    cin >> n >> k;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    pair<int,int> *r = new pair<int, int>[n] {};
    for (int i = 0, j = k, h = 0, m = 0; j > 0; i++)
        switch (h = g(i, j, h).Y) {
            case 1: --j; r[i].Y = r[i+1].Y = ++m; break;
            case 2: --j; r[i].X = r[i+1].X = ++m; break;
            case 3: --j; r[i].X =   r[i].Y = ++m; break;
        }

    for (int i = 0; i < n; i++)
        cout << r[i].X << " " << r[i].Y << "\n";
    return 0;
}

//ll f(int i, int j, int h){
//    if (j == 0)
//        return 0;
//    set<int> s;
//    if (n - i > j)
//        s.insert(f(i+1, j, 0));
//    if ((n - i > j) && (h != 1))
//        s.insert(b[i] + b[i+1] + f(i+1, j-1, 1));
//    if ((n - i > j) && (h != 2))
//        s.insert(a[i] + a[i+1] + f(i+1, j-1, 2));
//    if ((h != 1) && (h != 2))
//        s.insert(a[i] + b[i] +   f(i+1, j-1, 3));
//    return *(--s.end());
//}
