#include <iostream>
using namespace std;

int FindMax(int *a, int n){
    int m = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}

int main()
{
    freopen("tests/01", "r", stdin);
    int w, n, m;
    cin >> w >> n >> m;
    int *a = new int[n], *b = new int[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int m1 = FindMax(a, n), m2 = FindMax(b, m);
    if (m1 > m2)
        swap(m1, m2);

    int l = 1000000; //поправить l
    for (int i = m1; i <= w - m2; i++){
        int w1 = i, w2 = w - i, l1 = 1, l2 = 1;
        for (int j = 1, s = a[0]; j < n; j++)
            if (s + a[j] + 1 >= w1){
                l1++;
                s = a[j];
            }
            else
                s += a[j] + 1;
        for (int j = 1, s = b[0]; j < m; j++)
            if (s + b[j] + 1 >= w2){
                l2++;
                s = b[j];
            }
            else
                s += b[j] + 1;
        if (max(l1, l2) < l)
            l = max(l1, l2);
    }

    cout << l;
    return 0;
}
