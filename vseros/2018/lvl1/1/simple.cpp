#include <iostream>
using namespace std;

long long a, b;

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> a >> b;
    a -= !(a % 2);
    b -= !(b % 2);
    long long n = (a + 1) / 2;
    long long m = (b + 1) / 2;
    cout << (m > n ? m - n : n - m);
    return 0;
}
