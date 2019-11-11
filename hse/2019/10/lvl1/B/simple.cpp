#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001];

int simple(){
    sort(a, a + n);
    int s = 0, q = 1;
    for (int i = 0; i < n; i++){
        if ((a[i] < a[i + 1]) || (a[i + 1] == 0)){
            s += (q / a[i])*a[i];
            q = 1;
        } else q++;
    }
    return s;
}

int main()
{
    //freopen("tests/02", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 0;

    cout << simple();
    return 0;

}
