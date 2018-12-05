#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
   //freopen("tests/00", "r", stdin);
    int n;
    cin >> n;
    double s = (int)log2(5);
    cout << s;
    cout << ((n % 2 == 0) ? (int)log2(n) + 2 : (int)log2(n) + 3);
    return 0;
}
