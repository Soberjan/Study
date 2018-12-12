#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

const int NLIM = 32;
int n, h, f, a[NLIM];
int main ()
{
  //  freopen("tests/01", "r", stdin);

    cin >> n >> h >> f;
    for (int i = 0; i < h; i++)
        cin >> a[i];

    int smax = 0;
    for (int i = 0, s = 0; i < (1<<(n-1)); i++, smax=max(s, smax), s = 0)
        if (__builtin_popcount(i) == f){
            bitset<32> w(i);
            w.set(0);
            w.set(n);
            for (int l = 0, r = w._Find_next(l); r <= n; l = r, r = w._Find_next(l)){
                int* p = upper_bound(a, a + h, r) - 1;
                if ((p < a) || (*p <= l))
                    s += r - l;
            }
        }
    cout << smax;
    return 0;
}
