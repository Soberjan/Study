#include <iostream>
#include <algorithm>
using namespace std;

int n, *s;
long long k, t;

int main(){
//    freopen("tests/01", "r", stdin);
    cin >> n >> k >> t;
    s = new int[n];
    for (int i = 0; i < n; i++){
        char e; int a, b;
        cin >> a >> e >> b;
        s[i] = a * b;
    }

    sort (s, s + n);
    int m = k * t, q = 0;
    for (int i = 0; i < n; i++){
        m -= s[i];
        if (m < 0)
            break;
        q++;
    }

    cout << q;
    return 0;
}
