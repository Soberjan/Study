#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n, k, * a;
long long p;

int optimal(){
    int s = 0;
    for (int i = 0; i < n; i++){
        s += a[i] / k;
        a[i] = a[i] % k;
    }
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++){
        if (k - a[i] <= p){
            s += 1;
            p -= k - a[i];
        }
        else break;
    }
    s += p / k;
    return s;
}

int main()
{
    //freopen("tests\\00", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> p >> k;
    a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << optimal();
    delete[] a;
    return 0;
}
