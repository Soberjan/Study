#include <iostream>
#include <set>
#include <map>
using namespace std;
#define X first
#define Y second
#define ll long long

int n, k;
pair<int, int> *a;
ll *c;
#define f(i,j,h) c[(i)*(k+1)*4 + (j)*4 + (h)]

pair<ll, int> g(int i, int j, int h){
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
        s.insert({f(i+1, j-1, 3) + a[i].X + a[i].  Y, 3});
    return s.size() > 0 ? *(--s.end()) : (pair<ll, int>) {0, 0};
}

int main(){
    //freopen("tests/01", "r", stdin);
    cin >> n >> k;
    a = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;

    c = new ll[(n+1)*(k+1)*4]{0};
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= k; j++)
            for (int h = 0; h < 4; h++)
                f(i, j, h) = g(i, j, h).X;
    pair<int, int> *b = new pair<int, int>[n];
    for (int i = 0, j = 1, h = 0; j <= k; i++)
        switch (h = g(i, k-j+1, h).Y){
            case 1: b[i].Y = b[i+1].Y = j; j++; break;
            case 2: b[i].X = b[i+1].X = j; j++; break;
            case 3: b[i].X = b[i]  .Y = j; j++; break;
        }
    for (int i = 0; i < n; i++)
        cout << b[i].X << " " << b[i].Y << endl;
    return 0;
}

