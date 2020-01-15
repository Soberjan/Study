#include <iostream>
using namespace std;
#define ull unsigned long long

int n, p, x, *a;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> n >> p >> x;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ull m = 1;
    for (int i = 0; (i < n) && (m % p != x); i++){
        m *= a[i];
	cout << a[i] << " ";
    }

    return 0;
}
