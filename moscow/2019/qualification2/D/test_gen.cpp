#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int main(int c, char** v){
    srand(atoi(v[1]) + time(0));
    int n = atoi(v[2]);
    int k = atoi(v[3]);
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++)
        cout << rand() % atoi(v[4]) + 1 << " ";
    return 0;
}
