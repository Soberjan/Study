#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

const int NLIM = 50;
const int VLIM = 30;

int main(int c, char* v[])
{
    srand(atoi(v[1]) + time(0));
    int n = NLIM - rand() % (NLIM / 2);
    int k = rand() % (n / 2) + 2;
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++)
        cout << rand() % VLIM + 1 << " ";
    return 0;
}
