#include <iostream>
#include <algorithm>
using namespace std;

int n, k, *a = new int [100000];

int main()
{
   // freopen("tests/01", "r", stdin);
    cin >> n >> k;
    int *b = new int [n - k + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - k + 1; i++){
        int *c = new int [k];
        for (int j = 0; j < k; j++)
            c[j] = a[i + j];
        sort(c, c + k);
        b[i] = c[k/2];
    }
    for (int i = 0; i < n - k + 1; i++)
        cout << b[i] << ' ';
    return 0;
}
