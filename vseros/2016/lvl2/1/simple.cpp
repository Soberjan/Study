#include <iostream>
using namespace std;

int n, k;

int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> n >> k;
    cout << (long long) (n/2 + 1) * (k/2 + 1);
    return 0;
}
