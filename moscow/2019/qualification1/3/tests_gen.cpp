#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

const int NLIM = 20;
int n, *a = new int [100000];

int main(){
    srand(time(0));
    n = 4294967296;
    cout << n << endl;
    for (; n != 1; n/=2)
        for (int i = 0; i < n/2; i++)
            cout << rand() % 2 + 1 << endl;

    return 0;
    }
