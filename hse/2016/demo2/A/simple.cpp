#include <iostream>
#include <cmath>
using namespace std;

int simple(int n, int m, int k){
    int s = n / (k - 2);
    if ((s * 2 > m) || ((s * 2 == m) && (n % (k - 2) != 0)))
        return 0;
    m -= s * 2;
    int q = n % (k - 2);
    if (q == 0)
        return s + ceil(double(m) / double(k));
    if (k - q >= 2)
        return s + 1 + ceil(double(m - 2) / double(k));
    return s + 2 + ceil(double(m - 2 - (k - q)) / double(k));
}

int main()
{
//    freopen("tests/00", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;

    int ans = simple(n, m, k);

    cout << ans;
    return 0;
}
