#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
#define X first
#define Y second

int t, n, m;
pair<int, int> *a, *b;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> t >> n;
    a = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].X>> a[i].Y;
    cin >> m;
    b = new pair<int, int>[m];
    for (int i = 0; i < m; i++)
        cin >> b[i].X >> b[i].Y;
    for (int i = 0; i < n; i++)
        a[i].Y += t;
    for (int i = 0; i < m; i++)
        b[i].Y += t;
    int p = n + m;
    pair<pair<int, int>, int> *c = new pair<pair<int, int>, int>[p];
    for (int i = 0; i < n; i++)
        c[i] = {a[i], 1};
    for (int i = 0; i < m; i++)
        c[n+i] = {b[i], 2};
    sort (c, c + p);

    list<int> station1, station2;
    for (int i = 0; i < p; i++){
        if (c[i].Y == 1){
            int dep = c[i].X.X;
            int arr = c[i].X.Y;
            bool e = 0;
            for (list<int>::iterator it = station1.begin(); it != station1.end(); ++it)
                if (*it <= dep){
                    station1.erase(it);
                    station2.push_back(arr);
                    e = 1;
                    break;
                }
            if (e)
                continue;
            station2.push_back(arr);
        }
        if (c[i].Y == 2){
            int dep = c[i].X.X;
            int arr = c[i].X.Y;
            bool e = 0;
            for (list<int>::iterator it = station2.begin(); it != station2.end(); ++it)
                if (*it <= dep){
                    station2.erase(it);
                    station1.push_back(arr);
                    e = 1;
                    break;
                }
            if (e)
                continue;
            station1.push_back(arr);
        }
    }
    cout << (int)station1.size() + (int)station2.size();
    return 0;
}
