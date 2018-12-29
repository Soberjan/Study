#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

const int NLIM = 15;
const int VLIM = 20;
int n, a[100], b[100];

void CreateTest(int i){
    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    n = NLIM - rand()%(NLIM/2);
    cout << n << endl;
    for (int i = 1; i <= n; i++){
        int c = rand() % n + 1;
        while (a[c]==1)
            c = rand() % n + 1;
        a[c]=1;
        cout << c << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        int c = rand() % n + 1;
        while (b[c]==1)
            c = rand() % n + 1;
        b[c]=1;
        cout << c << " ";
    }
    cout << endl;
    fclose(stdout);
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    for (int i = 1; i <= n; i++)
        b[i] = 0;
    }



int main(){
    srand(time(0));
    for (int i = 10; i < 16; i++)
        CreateTest(i);
    return 0;
    }
