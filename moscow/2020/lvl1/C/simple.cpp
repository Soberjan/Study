#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int n, *a;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    pair<ll, int> p{0,0};
    ll s = 0;
    for (int i = 0; i < n; i++)
        if ( (n - i) * a[i] > s )
            s = (n - i) * a[i], p = {n - i, a[i]};

    cout << p.first << " " << p.second;
    return 0;
}
