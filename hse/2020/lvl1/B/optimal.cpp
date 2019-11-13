#include <iostream>
using namespace std;

int n, k, **a = new int*[2];

int main(){
    freopen("tests/00", "r", stdin);
    cin >> n >> k;
    a[0] = new int[n];
    a[1] = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[0][i] >> a[1][i];



    return 0;
}
