#include <iostream>
using namespace std;

int n, p, q;
int *a;

int main(){
   // freopen("tests/02", "r", stdin);
    cin >> n >> p >> q;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int d = 0, e = n + 1;
    for (int i = 0, b = a[0] == 1, c = a[0] == 0; i < n; i++, b = a[i] == 1, c = a[i] == 0)
        for (int j = i + 1; j < n; j++){
            b += a[j] == 1;
            c += a[j] == 0;
            if ((b >= p) && (c >= q) && (j - i + 1 < e - d + 1)){
                d = i;
                e = j;
            }
        }
    cout << d + 1 << " " << e + 1;

    return 0;
}
