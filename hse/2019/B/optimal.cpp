#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n, a[100001];

int optimal(){

}

int main()
{
    //freopen("tests/02", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 0;

    cout << optimal();
    return 0;
}
