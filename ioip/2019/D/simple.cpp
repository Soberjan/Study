#include <iostream>
using namespace std;

int n, m, p, **a;

void print(int **a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int sum(int i1, int i2, int j1, int j2){
    int s = 0;
    for (int i = i1; i < i2; i++)
        for (int j = j1; j < j2; j++)
            s += a[i][j];
    return s;
}

int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> n >> m >> p;
    a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int smax = 0;
    for (int i = 2; i <= m; i++) //столбцы
        for (int j = 1; j <= i; j++) //строки
            for (int q = 0; q < n - j + 1; q++) //строки
                for (int k = 0; k < m - i + 1; k++){ //столбцы
                    int s = sum(q, q + j, k, k + i);
                    if ((s % p == 0) && (s > smax))
                        smax = s;
                }
    for (int j = 2; j <= n; j++) //строки
        for (int i = 1; i < j; i++) //столбцы
            for (int q = 0; q < n - j + 1; q++) //строки
                for (int k = 0; k < m - i + 1; k++){ //столбцы
                    int s = sum(q, q + j, k, k + i);
                    if ((s % p == 0) && (s > smax))
                        smax = s;
                }
    cout << smax;
    return 0;
}
