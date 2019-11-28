#include <iostream>
using namespace std;

int n, *a = new int [100000];

int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i];

    return 0;
}
