#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
    //freopen("check/01", "r", stdin);
    cin >> n;
    int a[11]; float q;
    for (int i = 0; i < 11; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++){
        cin >> q;
        int r = q <= 36 ? ceil(q / 4) : 10 - ceil((q - 36) / 2);
        a[r]++;
    }

    int smax = 0, s = 0;
    for (int i = 0; i < 10; i++){
        if (a[i] == 6)
            s++;
        else if (s != 0){
            smax = s;
            s = 0;
        }
    }

    cout << max(s, smax);
    return 0;
}
