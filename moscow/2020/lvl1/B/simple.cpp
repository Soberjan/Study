#include <iostream>
using namespace std;
#define ll long long

ll n, m, t;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> n >> m >> t;

    ll s = 0, k = 0, w = n, l = m;
    while (s <= t){
        s += (w * l - (w - 2) * (l - 2));
        w -= 2;
        l -= 2;
        k++;
    }

    cout << k - 1;
    return 0;
}
