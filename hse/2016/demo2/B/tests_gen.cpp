#include <iostream>
#include <time.h>
using namespace std;

const int NLIM = 40;
const int MLIM = 15;
int n, m;
char a[100000];

int main(){
    srand(time(0));

    int n = NLIM - rand()%(NLIM/2);
    int m = MLIM - rand()%(MLIM/2);
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            if (rand()%12 == 1)
                cout << "+";
            else
                cout <<"-";
	    cout << "\n";
	}

    return 0;
    }
