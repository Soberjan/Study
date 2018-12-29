#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;

int n, *a = new int [1000001], *b = new int [1000001];

void simple(){

}

int main()
{
   // freopen("tests/00", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    int eq;
    for (eq = 0; eq < n; eq++)
        if (a[eq]!=b[eq])
            break;

    int i;
    if (eq == n)
        cout << "No\n";
    else
        for (i = 1; i <= n; i++) {
            int j;
            for (j = 1; j<=n; j++)
                if (b[j]==i)
                    break;
            bitset<1000001> p; // позже увеличить значение битсета
            int l = a[i];
            p[l] = 1;
            bool br = 0;
            while (j != l){
                l = a[l];
                if (p[l]==1){
                    cout << "No\n";
                    br = 1;
                    break;
                }
            }
            if (br==1)
                break;
        }
    if (i == n + 1)
        cout << "Yes\n";

    return 0;
}
