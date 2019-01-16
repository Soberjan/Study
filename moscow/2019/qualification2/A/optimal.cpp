#include <iostream>
#include <stdio.h>
using namespace std;

int n;

int main()
{
    //freopen("tests/03", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    cout << n << " ";
    for (int i = 1; i < n; i++)
        cout << i << " ";
    return 0;
}
