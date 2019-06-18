#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int n;

void simple(){

}

bool comp(pair<int, int> l, pair<int, int> r){
    return (l.first < r.first) || ((l.first == r.first) && (l.second < r.second));
}

int main(){
    freopen("tests/03", "r", stdin);
   // pair<int, int> *a = new pair<int, int>[n]; //segmentation error if i use this
    pair<int, int> a[300];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> --a[i].first >> --a[i].second;

    sort(a, a + n, comp);

    pair<int, int> t1(0, 0), t2 (0, 0);
    for(int i = 0; i < a[n - 1].first; i++){
        int v = 0;
        pair<int, int> p(i, i + 5);
        for (int j = 0; j < n; j++)
            if ((a[j].first <= p.first) && (a[j].second <= p.second))
                v++;
        if (v > t1.first){
            if ((t1.first > t2.first) && (t2.second <= p.first - 5 )){
                t2.first = t1.first;
                t2.second = t1.second;
            }
            t1.first = v;
            t1.second = p.first;
        }
        else if ((v > t2.first) && (i <= t1.second - 5)){
            t2.first = v;
            t2.second = p.first;
        }
    }

    cout << t1.first + t2.first << " " << t1.second << " " << t2.second;

    cout << n << "\n";
    for(int i = 0; i < n; i++)
        cout << a[i].first << " " << a[i].second << "\n";

    return 0;
}
