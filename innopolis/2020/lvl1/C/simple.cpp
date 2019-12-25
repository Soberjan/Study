#include <iostream>
using namespace std;

int n, k, *a;

bool f(int i, int j){
    //cout << i << " " << j << endl;
    if ((i == n*2) && (j == 0))
        return 1;
    if ((i == n*2) || (j <= 0))
        return 0;
    bool r;
    for (int q = i+2; q <= n*2; q+=2)
        r |= f(q, j - (a[q-1] - a[i]));
    return r;
}

int main(){
    freopen("tests/01", "r", stdin);

    cin >> n >> k;
    a = new int[n*2];
    for (int i = 0; i < n*2; i++)
        cin >> a[i];

    cout << (f(0, k) ? "Yes" : "No");
    return 0;
}
