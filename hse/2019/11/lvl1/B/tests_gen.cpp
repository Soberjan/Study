#include <iostream>
#include <time.h>
using namespace std;

int main(int c, char* v[]){
    srand(atoi(v[1]));
    int n = atoi(v[2]) + rand() % atoi(v[2]), p = atoi(v[3]), q = atoi(v[4]);
    cout << n << " " << p + rand() % p << " " << q + rand() % q << "\n";
    for (int i = 0; i < n; i++)
        cout << rand() % 2 << " ";
    return 0;
    }
