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

    bitset<32> z;
    for (int i = 0; i < h; i++)
        z[a[i]-1] = 1;
    int smax = 0;
    for (int i = 0, s = 0; i < (1<<(n-1)); i++, smax=max(s, smax), s = 0)
        if (__builtin_popcount(i) == f){
            bitset<32> w(i);
            for (int l = 0, r = w._Find_first(), q = z._Find_first(); r < NLIM; l = r + 1, q = z._Find_next(r), r = w._Find_next(r))
                if (q>r)
                    s += r - l + 1;
        }
    cout << smax;
    return 0;
}
