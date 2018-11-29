#include <iostream>
#include <math.h>

using namespace std;

int n, k, x;

long long optimal(){
    long long z = ((x % (n - k)) >= 0.5) ? x / (n - k) + 1 : x / (n - k);
    return x + k * z;
}

int main()
{
    //freopen("tests\\02", "r", stdin);
    cin >> n >> k >> x;

    cout << optimal();
    return 0;
}
