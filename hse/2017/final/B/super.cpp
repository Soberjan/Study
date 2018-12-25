#include <iostream>

using namespace std;

int n, *a = new int[100000], *b = new int[100000];

int main()
{
    //freopen("check/06", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        b[n-i-1] = a[i];

    int m=0, m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++)
        if (a[i]>m)
            m = a[i];
    for (int i = 0; i < n; i++)
        if (a[i]==m){
            m1=i;
            break;
        }
    for (int i = 0; i < n; i++)
        if (b[i]==m){
            m2=i;
            break;
        }

    unsigned long long s = 0;
    for (int i = m1, max1 = m1 + 1; i<=n-m2-1; i++)
        if (a[i]>=a[max1]){
            for (int j = max1; j < i; j++)
                s+=a[max1]-a[j];
            max1=i;
        }
    for (int i = 0, max1 = 0; i<=m1; i++)
        if (a[i]>=a[max1]){
            for (int j = max1; j < i; j++)
                s+=a[max1]-a[j];
            max1=i;
        }
    for (int i = 0, max1 = 0; i<=m2; i++)
        if (b[i]>=b[max1]){
            for (int j = max1; j < i; j++)
                s+=b[max1]-b[j];
            max1=i;    //язь, не проходит по памяти
        } // код можно укоротить: написать в третье цикле break при a[i]==m. за счет этого можно 3 цикла убрать
    cout << s << endl;

    return 0;
}
