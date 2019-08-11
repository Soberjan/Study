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
    int *tmp = new int[k];
    memcpy(tmp, a, sizeof(int) * k);
    sort(tmp, tmp + k);
    int fst = 0, lst = k;
    for (int i = 0; i <= n - k + 1; fst++, lst++, i++){
        b[i] = tmp[k/2];
        int *idx1 = lower_bound(tmp, tmp + k, a[fst]);
        for (int j = idx1 - tmp + 1; j < k; j++)
            tmp[j - 1] = tmp[j];
        int *idx2 = lower_bound(tmp, tmp + k, a[lst]);
        for (int j = k - 1; j > idx2 - tmp; j--)
            tmp[j] = tmp[j - 1];
        if (idx2 - tmp == k)
            tmp[k - 1] = a[lst];
        else
            tmp[idx2 - tmp] = a[lst];
    }
}

int main()
{
    //freopen("tests/02", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *b = new int[n - k + 1];
    optimal(b);
    print(b, n - k + 1);
    return 0;
}
