#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main(int c, char* v[]){
    default_random_engine generator(atoi(v[1]) + time(0));
    int n = atoi(v[2]), k = atoi(v[3]);
    uniform_int_distribution<int> vdist(1, 1000000000);
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++)
        cout << vdist(generator) << " " << vdist(generator) << "\n";
    return 0;
    }
