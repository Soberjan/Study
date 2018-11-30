#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

const int NLIM = 32;
int n, h, f, a[NLIM], smax = 0;
bitset<32> b;

int main ()
{
    //freopen("tests/03", "r", stdin);
    cin >> n >> h >> f;
    for (int i = 0; i < h; i++)
        cin >> a[i];

    for (int i = 0; i < h; i++)
        b[a[i] - 1] = 1;

    for (int i = 0, s = 0, smax = 0; i < (1<<(n-1)); i++, smax=max(s, smax), s = 0)
        if (__builtin_popcount(i) == f){
            bitset<32> c(f);
            int lwall = 0, rwall = 0, inf = 0;
            for (int j = 0; j < n; j++){
                if (b[j] == 1)
                    inf = 1;
                if (c[j] == 1){
                    lwall = j + 1;
                    if (inf == 0){
                        s += lwall - rwall;
                        rwall = lwall;
                        lwall = n;
                    }
                    inf = 0;
                }
            }
        }
    cout << smax;
    return 0;
}
