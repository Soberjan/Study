#include <iostream>
#include <algorithm>
using namespace std;

long long a[3];

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> a[0] >> a[1] >> a[2];
    sort (a, a + 3);
    cout << a[1];
    return 0;
}
