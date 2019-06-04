#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, *a = new int [1000010];

void print(int* a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i];
}

int* optimal(){
    int *c = new int[n - k + 1], *tmp = new int[k];
    memcpy(tmp, a, 4 * k);
    sort(tmp, tmp + k);
    int fst = 0, lst = k;
    for (int i = 0; i < n - k + 1; i++){
        c[i] = tmp[k/2];
        int *idx = lower_bound(tmp, tmp + k, a[fst]);
        for (int j = *idx + 1; j < k; j++)
            tmp[j - 1] = tmp[j];
        idx = lower_bound(tmp, tmp + k, a[lst]);
        for (int j = *idx + 1; j < k - 1; j++)
            tmp[j + 1] = tmp[j];
        tmp[*idx] = a[lst];
    }
    return c;
}

int main()
{
    //freopen("tests/02", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *b = new int[n - k + 1];
    b = optimal();
    for (int i = 0; i < n; i++)
        cout << b[i];
    return 0;
}
