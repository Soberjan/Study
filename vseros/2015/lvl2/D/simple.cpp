#include <iostream>
#include <vector>
using namespace std;

int n;
int *a;

int f(int q, int k, int s1, int s2){
    q = q/2;
    int i = q;
    int m = s2;
    while (q != 0){
        q /= 2;
        if (s2 - i < s1 + i * k)
            m = min(m, max(m - i, s1 + i * k)), i -= q;
        if (s2 + i > s1 + i * k)
            m = min(m, max(m - i, s1 + i * k)), i += q;
    }
    return m;
}

int main(){
//    freopen("tests/00", "r", stdin);
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;
    for (int i = n - 1, k = 0, j; ; i = j){
        for (j = i; ( (j != -1) && (a[j] == a[i]) ); j-- )
            k++;
        if (s + k * (a[i] - a[j]) <= a[j]){
            s += k * (a[i] - a[j]);
            fill(a + j, a + i + 1, a[j]);
        }
        else{
            s = f(a[i]-a[j], k, s, a[i]);
            break;
        }
    }
    cout << s;
    return 0;
}
