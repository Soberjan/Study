#include <iostream>

using namespace std;
const int NLIM = 100000;
int n, a[NLIM];

int optimal(int lo, int hi){
    if (lo<hi){
        int m = lo;
	long long s = 0;
        for (int i = lo; i < hi; i++)
            if (a[i] > a[m])
                m = i;
        for (int i = m; i<hi; i++)
            s += a[m]-a[i];
        s += optimal(lo, m);
        return s;
    }
    else
        return 0;
}

int optimal1(int lo, int hi){
    if (lo<hi){
        int m = lo+1;
        long long s = 0;
        for (int i = lo + 1; i <= hi; i++)
            if (a[i] > a[m])
                m = i;
        for (int i = lo + 1; i <= m; i++)
            s += a[m]-a[i];
        s += optimal1(m, hi);
        return s;
    }
    else
        return 0;
}

int main(){
//    freopen("tests\\04", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m = 0, m2 = 0;
    for (int i = 0; i < n; i++)
        if (a[i]>a[m])
            m = i;
    for (int i = n - 1; i > 0; i--)
    if (a[i]==a[m]){
        m2 = i;
        break;
    }

    long long s = 0;
    for (int i = m + 1; i < m2; i++)
        s += a[m]-a[i];
    s += optimal(0, m);
    s += optimal1(m2, n - 1);

    cout << s;
    return 0;
}
