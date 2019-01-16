#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

const int NLIM = 15;
const int VLIM = 20;
int n, *a = new int [100000];

int main(){
    srand(time(0));
    n = NLIM - rand() % (NLIM/2);
    for (int i = 0; i < n; i++)
	a[i] = VLIM - rand() % (VLIM/2);

    cout << n << endl;
    for (int i = 0; i < n; i++)
       cout << a[i] << " ";
    return 0;
    }
