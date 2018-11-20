#include <iostream>
#include <math.h>

using namespace std;

long n, k, x;

long long optimal(){
    long long z = ceil(double(x) / (n - k));
    return x + k * z;
}

int main()
{
    //freopen("tests\\02", "r", stdin);
    cin >> n >> k >> x;

    cout << optimal();
    return 0;
}
