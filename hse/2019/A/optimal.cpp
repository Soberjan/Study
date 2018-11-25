#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("tests/04", "r", stdin);
    int n, p, q;
    cin >> n >> p >> q;

    int minim = 0;
    int maxim = 0;
    int a = p - 1;
    int d = n - q;
    int r = d - a;
    if (r > 0){
        minim = 1;
        maxim = max(p, q);
    }
    if (r == 0){
        minim = 1;
        maxim = n;
    }
    if (r < 0){
        minim = a - d + 1;
        maxim = n;
    }
    if ((p == 1) || (q == 1)){
        minim = 1;
        maxim = p = 1 ? q : p;
    }
    if ((p == n) || (q == n)){
        minim = p = n ? q : p;
        maxim = n;
    }

    cout << minim << " " << maxim;
    return 0;
}
