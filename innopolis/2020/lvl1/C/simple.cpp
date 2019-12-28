#include <iostream>
using namespace std;
#define X first
#define Y second

int n, k, *a;

pair<bool, int> g(int i, int q);
bool f(int i, int q){ return g(i, q).X; }
pair<bool, int> g(int i, int q){
    if ((i == n*2) && (q == 0))
        return {1, i};
    if ((i == n*2) || (q <= 0))
        return {0, i};
    pair<bool, int> p{0, i};
    for (int j = i+2; (!p.X) && (j <= n*2); j+=2)
        p = {f(j, q - (a[j-1] - a[i])), j};
    return p;
}

int main(){
//    freopen("tests/02", "r", stdin);

    cin >> n >> k;
    a = new int[n*2];
    for (int i = 0; i < n*2; i++)
        cin >> a[i];

    if (!f(0, k)){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0, q = k, j = 0; q > 0; q -= a[j-1] - a[i], i = j){
        j = g(i, q).Y;
        cout << i + 1 << " " << j << endl;
        for (int u = i+1, v = j-1; u < v; u++, v--)
            cout << u+1 << " " << v << endl;
    }
    return 0;
}
