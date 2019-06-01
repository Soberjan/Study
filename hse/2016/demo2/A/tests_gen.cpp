#include <iostream>
#include <time.h>
using namespace std;

const int NLIM = 100;
const int MLIM = 80;
const int KLIM = 30;

int main(){
    srand(time(0));
    
    int n = NLIM - rand()%(NLIM/2);
    int m = MLIM - rand()%(MLIM/2);
    int k = KLIM - rand()%(KLIM/2);
    cout << n << " " << m << " " << k;

    return 0;
    }
