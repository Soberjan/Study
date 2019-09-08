#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int main(int c, char** v)
{
    srand(atoi(v[1]) + time(0));
    const int WLIM = atoi(v[2]), NLIM = atoi(v[3]), MLIM = atoi(v[4]), VLIM = atoi(v[5]);
    int w = WLIM - rand() % (WLIM / 2);
    int n = NLIM - rand() % (NLIM / 2);
    int m = MLIM - rand() % (MLIM / 2);
    cout << w << " " << n << " " << m << "\n";
    int *a = new int[n], *b = new int[m];
    for (int i = 0; i < n; i++)
        a[i] = rand() % VLIM + 1;
    for (int i = 0; i < m; i++)
        b[i] = rand() % VLIM + 1;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
    return 0;
}
