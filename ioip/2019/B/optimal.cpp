#include <iostream>
using namespace std;

int w, n, m, *a, *b;

int f(int* c, int n, int w){
    int l = 1, s = 0;
    for (int i = 0; i < n; i++){
        if (c[i] > w)
            return -1;
        s += c[i];
        if (s > w){
            l++;
            s = c[i] + 1;
        }
        else
            s++;
    }
    return l;
}

int main(){
   // freopen("tests/02", "r", stdin);
    cin >> w >> n >> m;
    a = new int[n], b = new int[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int l = 1000000000;
    for (int i = w / 2 + w % 2, j = w / 2; j > 0; ){
        int m1 = f(a, n, i);
        int m2 = f(b, m, w - i);
        if ((m1 != -1) && (m2 != -1))
            l = l > max(m1, m2) ? max(m1, m2) : l;
        j /= 2;
        if (((m1 > m2) || (m1 == -1)) && (m2 != -1))
            if (j == 0)
                i++;
            else
                i += j;
        else
            if (j == 0)
                i--;
            else
                i -= j;
    }

    cout << l;
    return 0;
}
