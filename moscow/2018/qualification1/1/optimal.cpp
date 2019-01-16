#include <iostream>
#include <stdio.h>
using namespace std;

int a, b, c;

int main()
{
    //freopen("tests/03", "r", stdin);
    cin >> a >> b >> c;
    cout << (long long)(b-a)/c + 1;

    return 0;
}
