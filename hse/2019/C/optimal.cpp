#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;

const int NLIM = 10000;
int n, h, f;

int main()
{
    freopen("tests/04", "r", stdin);
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

    int s = 0;
    map<int, int>::iterator it;
    map<string, int>::iterator x;
    for ( x = t.begin(); x != t.end(); x++ ){
        if (f-3 > x.second*2){
            s+=x.second*x.first;
            f-=x.second*2;
        }
        if (f-3 == x.second*2){
            s+=(f-3)/2*x.first;
            f = f%2==0 ? f=2 : f=3;

            break;
        }
        if (f-3 < x.second*2){
            s+=(f-3)/2*x.first;
            f = f%2==0 ? f=2 : f=3;
            it = x;
            break;
        }
    }

//    int first = a[0] - 1;
//    int last = n - a[h - 1];
//    int sumt = 0;
//    if (f == 3){
//        sumt = max(sum + b[j] + b[0], sum + b[j] + b[h]);
//        sum = max(sumt, sum + b[0] + b[h]);
//    }
//    if (f == 2)
//        sum = max(sum + b[j], sum + b[0] + b[h]);

    cout << s;
    return 0;
}



//    const int NLIM = 10000;
//    int n, h, f, a[NLIM];
//    cin >> n >> h >> f;
//    for (int i = 0; i < h; i++)
//        cin >> a[i];
//
//    int b[NLIM];
//    for (int i = 1; i < h; i++)
//        b[i] = a[i] - a[i - 1] - 1;

//    sort(b + 1, b + h, greater<int>());
//
//    int sum = 0;
//    int j;
//    for (int i = 1; i < h; i++){
//            if (f > 3){
//                f -= 2;
//                sum += b[i];
//            }
//            if (f <= 3){
//                j = i;
//                break;
//            }
//        }
//
//    cout << sum;
