#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define X first
#define Y second

int n, k;
vector<int> a, b;

ll f(int i, int j, int h){
    if (j == 0)
        return 0;
    set<int> s;
    if (n - i > j)
        s.insert(f(i+1, j, 0));
    if ((n - i > j) && (h != 1))
        s.insert(b[i] + b[i+1] + f(i+1, j-1, 1));
    if ((n - i > j) && (h != 2))
        s.insert(a[i] + a[i+1] + f(i+1, j-1, 2));
    if ((h != 1) && (h != 2))
        s.insert(a[i] + b[i] +   f(i+1, j-1, 3));
    return *(--s.end());
}

int main(){
    freopen("tests/03", "r", stdin);
    cin >> n >> k;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    cout << f(0, k, 0);

    return 0;
}
