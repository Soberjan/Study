#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

const int NLIM = 15;
const int VLIM = 20;
int n, *a = new int [100000];

int main(){
    srand(time(0));
    
    int b = rand()%15000;
    int a = rand()%b;
    int c = rand()%100;
    cout << a << endl << b << endl << c << endl;

    return 0;
    }
