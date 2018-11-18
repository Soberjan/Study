#include <iostream>
#include <math.h>

using namespace std;

long n, k, x;

long optimal(){
//    if (x < n - k)
//        return n;
    long z = ceil(double(x) / (n - k));
    return x % (n - k) ? x + k * z : n * z;
}

int main()
{
    //freopen("tests\\02", "r", stdin);
    cin >> n >> k >> x;

    cout << optimal();
    return 0;
}
