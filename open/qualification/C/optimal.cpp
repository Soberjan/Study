#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long n, p, k, a[50];

long optimal(){
    sort(a, a + n, [](int l, int r){ return (l > k ? l % k : k - l) < (r > k ? r % k : k - r );});
    int s = 0;
    for (int i = 0; i < n; i++){
        if (p > 0){
            if (a[i] < k){
                s += 1;
                p -= k - a[i];
            }
            if (a[i] >= k){
                if (a[i] / k == 0)
                    s += a[i] / k;
                if (a[i] % k > 0){
                    s += (a[i] + k - a[i] % k) / k;
                    p -= k - a[i] % k;
                }
            }
        }
    }
    return (p > 0 ? s += p / k : s);
}

int main()
{
    freopen("tests\\00", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << optimal();
    return 0;
}
