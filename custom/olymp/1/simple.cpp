#include <iostream>
#include <algorithm>
using namespace std;

int n, *a, **m;

int main()
{
    //freopen("tests/01", "r", stdin);
    cin >> n;
    a = new int[n];
    m = new int*[n];
    for (int i = 0; i < n; i++)
        m[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    a[0] = m[0][1] / sqrt((long long)m[0][1] * m[1][2] / m[0][2]);
    for (int i = 1; i < n; i++)
        a[i] = m[0][i] / a[0];

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
