#include <iostream>
#include <time.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int NLIM = 15;
const int MLIM = 15;
int n, m, a[100];
pair<int, int> b[100];

int main(){
    srand(time(0));
    n = NLIM - rand() % (NLIM/2);
    m = MLIM - rand() % (MLIM/2);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    random_shuffle(a, a + n);
    for (int i = 0, q = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            b[q].first = j + 1, b[q].second = i + 1, q++;
    random_shuffle(b, b + m);
    sort (b, b + m);
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < m; i++)
        cout << b[i].first << " " << b[i].second << "\n";

    return 0;
    }
