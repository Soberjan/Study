#include <iostream>
#include <time.h>
using namespace std;

const int NLIM = 20;
const int VLIM = 20;

int main(){
    srand(time(0));

    int n = NLIM - rand()%(NLIM/2);
    cout << n << "\n";
    for (int i = 0, q = rand()%VLIM + 1; i < n; q = rand()%VLIM + 1, i++)
        cout << q << " " << q + rand() % VLIM << "\n";

    return 0;
    }
