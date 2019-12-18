#include <iostream>
using namespace std;
#define ll long long
#define X first
#define Y second

const ll INF = 2 * 1e10;
int n, l1, r1, l2, r2, s1, d1, s2, d2;

pair<int, int> f(){
    int x = max(l1, l2);
    int y = min (r1, r2);
    if (x >= y)
        return {l1, l2};
    pair<int, int> p{-1, -1};
    ll mins = INF;
    for (int i = x; i <= y; i++){
        if ( (i - d1 >= l1) && (i + d2 <= r2) )
            if ( abs(s1 - (i - d1)) + abs(s2 - i) < mins )
                mins = abs(s1 - (i - d1)) + abs(s2 - i), p = {i - d1, i};
        if ( (i - d2 >= l2) && (i + d1 <= r1) )
            if ( abs(s2 - (i - d2)) + abs(s1 - i) < mins )
                mins = abs(s2 - (i - d2)) + abs(s1 - i), p = {i, i - d2};
    }
    return p;
}

int main(){
//    freopen("tests/00", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> l1 >> r1 >> l2 >> r2 >> s1 >> d1 >> s2 >> d2;
        pair<int, int> p = f();
        cout << p.X << " " << p.Y << "\n";
    }


    return 0;
}
