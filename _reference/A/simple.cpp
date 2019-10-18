#include <iostream>
#include <list>
using namespace std;

int n, *a = new int [100000];

int main()
{
//    freopen("tests/00", "r", stdin);
    list<int> b;
    b.push_back(100);
    b.push_back(100);
    b.push_back(100);
    b.push_back(100);
    b.push_back(100);
    b.push_back(100);
    b.push_back(100);
    for (i : b)
        cout << i;
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i];

    return 0;
}
