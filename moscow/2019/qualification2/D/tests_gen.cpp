#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

const int NLIM = 20;
int n, k, a[20];

int main(){
    srand(time(0));
    n = NLIM - rand()%(NLIM/2);
    k = rand()%(n-2) + 2;
    for (int i = 0; i < n; i++)
        a[i] = rand() % NLIM + 1;

    cout << n << ' ' << k << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
