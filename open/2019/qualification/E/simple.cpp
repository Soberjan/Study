#include <iostream>
#include <stdio.h>
#include <bitset>
#include <set>
using namespace std;
#define X first
#define Y second

const int NLIM = 30;
int n, m;
pair<int, int> *a;

set<int> simple(){
    set<int> s;

    for (int i = 1; i <= n; i++)
        for (int c = 0; c < 1<<(n-1); c++){
            int x = (c>>(i-1)<<i) | (c & ((1<<(i-1))-1));
            bitset<NLIM> bs(x<<1);
            //cout << bs << endl;
            bool match = 1;
            for (int j = 0; j < m; j++)
                if ((a[j].X != i) && (a[j].Y != i) && (bs[a[j].X] == bs[a[j].Y])) {
                    match = 0;
                    break;
                }
            if (match){
                s.insert(i);
                break;
            }

        }

    return s;
}

int main()
{
    //freopen("tests/03", "r", stdin);
    cin >> n >> m;
    a = new pair<int, int>[m];
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;

    set<int> s = simple();
    cout << s.size() << "\n";
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    return 0;
}
