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
            double disc = 1 + 8*m/k;
            n = (-1 + (unsigned long long)floor(sqrt(disc)))/2;
            unsigned long long s = (n+1)/2*n;
            unsigned long long ost = m / k - s;
            unsigned long long stuff = ost * k;
            unsigned long long ans = n * k + stuff;
            cout << ans << "\n";
        }
        else
            cout << m << "\n";
    }

    return 0;
}
