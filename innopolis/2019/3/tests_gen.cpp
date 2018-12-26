#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

const int NLIM = 15;
const int VLIM = 20;
int n, *a = new int [100000], b[100000];

int main(){
    srand(time(0));
    n = 14;
    for (int i = 2; i <= n; i++)
	a[i] = 1 + rand()%(i-1);
    for (int i = 1; i <= n; i++)
	b[i] = rand()%20;	
    cout << n << endl;
    for (int i = 0; i < n; i++)
       cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
       cout << b[i] << " ";
    return 0;
    }
