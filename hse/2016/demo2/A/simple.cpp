#include <iostream>
#include <cmath>
using namespace std;

int simple(int n, int m, int k){
    int s = ceil(double(n) / (k - 2));
    if (s * 2 > m)
        return 0;
    m -= s * 2; n -= (s - 1) * (k - 2);
    m -= (k - 2 - n);
    s += ceil(double(m) / k);
    return s;
}

int main()
{
//    freopen("tests/02", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    cout << simple(n, m, k);
    return 0;
}
