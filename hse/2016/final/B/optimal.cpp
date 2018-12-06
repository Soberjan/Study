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
    int lg = log2(n);
    cout << (n <= (1<<lg) + (1<<(lg-1)) ? lg + 2 : lg + 3);
    return 0;
}
