#include <iostream>
using namespace std;
#define ll long long

int a, b, c, d, n;

int main(){
    cin >> a >> b >> c >> d >> n;

    int m = n * 7;
    ll s = 0;
    for (int i = 0, j = 1, q = 0; i < m; j++, i++)
        if (q == 0){
            if (j <= a)
                s += c;
            else
                s += d, j = 1, q = 1;
        }
        else if (q == 1){
            if (j <= b)
                s += d;
            else
                s += c, j = 1, q = 0;
        }

    cout << s;
    return 0;
}
