#include <iostream>
using namespace std;
#define ll long long

int n, l;
int *a, *b;

int main(){
    cin >> n >> l;
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
//    int n = 5, l = 5;
//    a = new int[5] {1,2,3,4,5};
//    b = new int[5] {5,4,3,2,1};

    ll m = 0;
    for (int i = 0; i < n; i++)
        m += a[i];
    int *c = new int[m];
    for (int i = 0, j = 0; i < n; j += a[i], i++)
        fill(c + j, c + j + a[i], b[i]);

    ll sum = 0;
    for (int i = 0; i < l; i++)
        sum += c[i];
    for (int i = 0, j = l; j < n; i++, j++){
        if (sum > sum - c[i] + c[j])
        sum = sum - c[i] + c[j],
        sum = max(sum, sum - c[i] + c[j]);
    }
    cout << sum;

    return 0;
}
