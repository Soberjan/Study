#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

unsigned long long t, m, k;

void simple(){

}

int main()
{
    freopen("tests/00", "r", stdin);
    cin >> t;
    for (unsigned long long i = 0; i < t; i++){
        cin >> m >> k;
        if (m > k){
            unsigned long long n;
            n = (k*(-1)+(unsigned long long)sqrt((unsigned long long)k*k+8*m*k))/(2*k);
            unsigned long long s = (2*k+k*(n-1))*n/2;
            unsigned long long ans = (m-s)/(n+1)+n*k;
            cout << ans << "\n";
        }
        else
            cout << m << "\n";
    }

    return 0;
}
