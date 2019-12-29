#include <iostream>
using namespace std;

int n;
string s;

int main(){
//    freopen("tests/02", "r", stdin);
    cin >> n >> s;
    int *a = new int[n]{};
    for (int i = 0; i < n; i++)
        a[i] = s[i] == 'm' ? 0 : 1;
    int i = 0, j = n - 1, q = 0;
    bool k = 0;
    while (i < j){
        if ((a[i] == !k) && (a[j] == k))
            k = !k, q++;
        i += (a[i] == k);
        j -= (a[j] == !k);
    }
    cout << q;
    return 0;
}
