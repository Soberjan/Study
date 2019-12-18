#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define X first
#define Y second

int n;
pair<int, int> *a;

int main(){
    cin >> n;
    a = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
//    n = 8;
//    a = new pair<int, int>[n] {{3, 9}, {11, 12}, {5, 7}, {4, 2}, {1, 9}, {6, 8}, {3, 5}, {9, 10}};

    for (int i = 0; i < n; i++){
        int t1 = a[i].X;
        int t2 = a[i].Y;
        a[i].X = min(t1, t2);
        a[i].Y = max(t1, t2);
    }
    multimap<int, int> m;
    for (int i = 0; i < n; i++)
        m.insert(a[i]);
    ll sum = 0;
    for (auto x : m)
        sum += x.Y;

    cout << sum;
    return 0;
}
