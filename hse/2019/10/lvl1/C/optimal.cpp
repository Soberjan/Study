#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;

const int NLIM = 10000;
int n, h, f;

int main()
{
//    freopen("tests/01", "r", stdin);
    cin >> n >> h >> f;
    int a[100000]; //10^9 - разобраться
    for (int i=0; i<h; i++)
        cin >> a[i];

    map<int, int, greater<int>> t;
    for (int i=0; i<h-1; i++)
        t[a[i+1]-a[i]-1] += 1;
    t.erase(0);
//    for (auto const& x : t)
//        cout << x.first << ':' << x.second << endl ;

    int sum = 0, ht = 0;
    for (auto const& x : t){
        if (f-3 > x.second*2){
            sum+=x.second*x.first;
            f-=x.second*2;
        }
        if (f-3 <= x.second*2){
            sum = f%2==0 ? sum+((f-3)/2+1)*x.first : (f-3)/2*x.first;
            f = f%2==0 ? f=2 : f=3;
            ht = f-3==x.second*2 ? x.first : x.first; //если условие истинно, то берем следующий элемент map. как это сделать?
            break;
        }
    }

    int first = a[0] - 1;
    int last = n - a[h - 1];
    if (f <= 3){
        int sumt = 0;
        if (f == 3){
            sumt = max(sum + first + last, sum + first + ht);
            sum = max(sumt, sum + last + ht);
        }
        if (f == 2)
            sum = max(sum + ht, sum + first + last);
        }
    else
        sum += first + last + ht;

    cout << sum;
    return 0;
}
