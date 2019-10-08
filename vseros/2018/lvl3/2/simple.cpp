#include <iostream>
#include <cmath>
using namespace std;

long long k;

int main()
{
    //freopen("tests/01", "r", stdin);
    cin >> k;
    long long a = k;
    long long i = 1;
    while (((long long)sqrt(a) * (long long)sqrt(a) != a) && (a <= 1000000000))
        a += (2 * (i++) - 1);
    if (a <= 1000000000)
        cout << sqrt(a);
    else
        cout << "none";
    return 0;
}
