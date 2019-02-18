#include <iostream>
#include <stdio.h>
using namespace std;

int a[100000000], n, k;

int main()
{
    //freopen("tests/03", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m = n - k + 1;
    int z = (m - k) / k;
    int b[100000000];
    for (int i = 0, s = 0; i < z; s = 0, i++){
        for (int j = i * k; j < k; j++)
            s += a[j];
        int q = s / k;
        for (int j = i * k; j < k; j++)
            b[j] = q;
    }
    for (int i = k * z + 1; i < m; i++)
        b[i] = a[i];
    for (int i = 0; i < m; i++)
        cout << a[i];
    return 0;
}
