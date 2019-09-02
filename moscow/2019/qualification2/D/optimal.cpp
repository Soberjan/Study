#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, *a = new int [1000010];

void print(int* a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void optimal(int *b){
    int *tmp = new int[k + 1];
    memcpy(tmp, a, sizeof(int) * k);
    sort(tmp, tmp + k);
    for (int i = 0; i <= n - k + 1; i++){
        b[i] = tmp[k/2];
        int *idx1 = lower_bound(tmp, tmp + k, a[i]);
        int *idx2 = lower_bound(tmp, tmp + k, a[i + k]);
        if (idx2 > idx1)
            memmove(idx1, idx1 + 1, (idx2 - idx1) * sizeof(int));
        else
            memmove(idx2 + 1, idx2, (idx1 - idx2) * sizeof(int));
        idx2 = lower_bound(tmp, tmp + k, a[i + k]);
        if (idx2 - tmp == k)
            tmp[k - 1] = a[i + k];
        else
            tmp[idx2 - tmp] = a[i + k];
    }
}

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *b = new int[n - k + 1];
    optimal(b);
    print(b, n - k + 1);
    return 0;
}
