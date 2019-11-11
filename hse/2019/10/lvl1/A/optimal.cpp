#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("tests/02", "r", stdin);
    int n, p, q;
    cin >> n >> p >> q;

    cout << (n-p-q+1>=0 ? 1 : p+q-n) << " " <<(n-p-q+1>0 ? p+q-1 : n);
    return 0;
}
