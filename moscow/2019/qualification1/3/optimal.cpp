#include <iostream>
#include <stdio.h>
using namespace std;

int n, *a = new long long [100000], *b = new long long [100000];

int main()
{
    freopen("tests/03", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[i]=i;
    int j = 1;
    for (; n != 1; n/=2){
        for (int i = 1; i <= n/2; i++, j++)
            b[i] = a[j] == 1 ? b[i*2-1] :b[i*2];
    }

    cout << b[1];
    return 0;
}
