#include <iostream>
//#include <algorithm>
using namespace std;
#define ll long long

int n, a, b;

int main(){
//    freopen("tests/04", "r", stdin);
    cin >> n >> a >> b;
    ll q = 0;
    for (int i = n % 2; (i <= b) && (i * 3 <= n); i+=2)
        q += ( (n - i * 3) / 2 <= a );
    ll p = (a + 1) * (b + 1);
    if (q == 0)
        cout << 0;
    else if (q == p)
        cout << 1;
    else{
        int g = __gcd(q, p);
        p /= g;
        q /= g;
        cout << q << "/" << p;
    }
    return 0;
}
