#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("tests/02", "r", stdin);
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (n % 2 == 0)
        for (int i = n / 2 - 1, j = n / 2; j != n; i--, j++)
            cout << a[i] << " " << a[j] << " ";
    else{
        cout << a[n/2] << " ";
        for (int i = n / 2 - 1, j = n / 2 + 1; j != n; i--, j++)
            cout << a[i] << " " << a[j] << " ";
    }
    return 0;
}
