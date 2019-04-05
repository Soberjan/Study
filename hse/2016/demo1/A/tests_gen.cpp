#include <iostream>
#include <time.h>
using namespace std;

const int NLIM = 15;
const int VLIM = 9;
int n, a[NLIM];

int main(){
    srand(time(0));
    n = NLIM - rand() % (NLIM / 2);
    for(int i = 0; i < n; i++)
        a[i] = rand() % VLIM + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
    }
