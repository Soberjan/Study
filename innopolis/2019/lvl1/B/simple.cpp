#include <iostream>
#include <set>
#include <list>
using namespace std;
#define X first
#define Y second

int n, *a;

int main(){
  //  freopen("tests/02", "r", stdin);
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> b;
    for (int i = 0; i < n; i++)
        b.insert(a[i]);
    pair<int, int> qmax = {0, 0};
    for (int i : b){
        list<int> c(a, a + n);
        c.remove(i);
        int q = 1, x = *(c.begin());
        for (int y : c)
            if (x != y)
                q++, x = y;
        qmax = max(qmax, {q, i});
    }

    cout << qmax.X << " " << qmax.Y;
    return 0;
}
