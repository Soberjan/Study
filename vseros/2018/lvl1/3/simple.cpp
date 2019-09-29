#include <iostream>
using namespace std;

int n, m;

int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> n >> m;
    unsigned long long s = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
            s += (m - i + 1) * (n - j + 1);
    }
    cout << s;
    return 0;
}
