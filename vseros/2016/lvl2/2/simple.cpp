#include <iostream>
using namespace std;

long long a, b, c, d;

long long euclid(long long x, long long y){
    while ((x != 0) && (y != 0))
        if (x > y)
            x = x - x / y * y;
        else
            y = y - y / x * x;
    return x + y;
}

int main()
{
//    freopen("tests/01", "r", stdin);
    cin >> a >> b >> c >> d;
    long long s = 0;
    while ( (a * d < b * c) && !( (a == c) && (b == d) ) ){
        a++; b++;
        long long e = euclid(a, b);
        a /= e; b /= e;
        s++;
    }
    cout << ( (a == c) && (b == d) ? s : 0 );
    return 0;
}
