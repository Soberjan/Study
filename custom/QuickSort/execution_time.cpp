#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

const int NLIM = 10000;
int a[NLIM];


int main()
{
    for (int j = 0; j < NLIM; j++)
        a[j] = rand() % 10;

    clock_t tStart = clock();
    sort(a, a + NLIM);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
