#include <iostream>
#include <time.h>
using namespace std;

const int NLIM = 20;
int n, *a = new int [100000];

int main(){
    srand(time(0));

    int n = NLIM - rand()%(NLIM/2);
    for (int i = 0; i < n; i++){
        int a = rand() % 3;
        if (a == 0)
            cout << "L";
        if (a == 1)
            cout << "B";
        if (a == 2)
            cout << "R";
    }
    cout << "\n";
    return 0;
    }
