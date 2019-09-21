#include <iostream>
#include <time.h>
using namespace std;

int n, m, p;

int main(int c, char** v){
    srand(atoi(v[1]) + time(0));
    n = atoi(v[2]);
    m = atoi(v[3]);
    p = atoi(v[4]);
    cout << n << " " << m << " " << p << "\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << rand() % p << " ";
        cout << "\n";
    }
    return 0;
}
