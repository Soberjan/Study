#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
const int NLIM = 10e5;
int n, k, a[NLIM], s;

void divide(int lo, int hi){
    int maximum = 0;
    for (int i = lo; i < hi; i++)
        if (a[i] >= a[maximum])
            maximum = i;
    for (int i = maximum; i < hi; i++)
            s += a[maximum] - a[i];
    if (maximum > lo)
        divide(lo, maximum);
    }

void simple(){
    int maximum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > a[maximum])
            maximum = i;

    divide(0, maximum);
    divide(maximum + 1, n);
}

int main(){
    //freopen("tests\\00", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    simple();

    cout << s;

    return 0;
}
