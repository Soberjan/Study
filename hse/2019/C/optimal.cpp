#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    //freopen("tests/04", "r", stdin);
    const int NLIM = 10000;
    int n, h, f, a[NLIM];
    cin >> n >> h >> f;
    for (int i = 0; i < h; i++)
        cin >> a[i];

    int b[NLIM];
    for (int i = 1; i < h; i++)
        b[i] = a[i] - a[i - 1] - 1;
    b[0] = a[0] - 1;
    b[h] = n - a[h - 1];
    sort(b + 1, b + h, greater<int>());

    int sum = 0;
    int j;
    for (int i = 1; i < h; i++){
            if (f > 3){
                f -= 2;
                sum += b[i];
            }
            if (f <= 3){
                j = i;
                break;
            }
        }
    int sumt = 0;
    if (f == 3){
        sumt = max(sum + b[j] + b[0], sum + b[j] + b[h]);
        sum = max(sumt, sum + b[0] + b[h]);
    }
    if (f == 2)
        sum = max(sum + b[j], sum + b[0] + b[h]);
    if (f == 1)
        sum = max(b[0], b[h]);

    cout << sum;
    return 0;
}
