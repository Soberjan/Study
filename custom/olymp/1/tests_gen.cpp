#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int c, char* v[]){
    srand(atoi(v[1]) + time(0));
    int n = atoi(v[2]);
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        cout << rand() % atoi(v[3]) + 1 << " ";

    return 0;
    }
