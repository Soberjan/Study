#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long n, k, a[100000];
long long p;

long optimal(){
    int b[100000];
    int s = 0;
    for (int i = 0; i < n; i++){
        b[i] = a[i] % k;
        s += a[i] / k;
    }
    sort(b, b + n, greater<int>());
    for (int i = 0; i < n; i++){
        if (b[i] == 0)
            break;
        if (k - b[i] <= p){
            s += 1;
            p -= k - b[i];
        }
    }
    s += p / k;
    return s;
}

int main()
{
    //freopen("tests\\00", "r", stdin);
//    cin.tie(0);
//    cout.tie(0);
//    ios_base::sync_with_stdio(false);
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = optimal();
    cout << ans;
    return 0;
}
