#include <iostream>
#include <set>
using namespace std;

int n, k, *a;

struct trio{ bool t; int j, q; };

set<int> s;
trio g(int i, int q);
bool f(int i, int q) { return g(i, q).t; }
trio g(int i, int q){
    if ( ((int)s.size() >= n * 2) && (q == 0) )
        return {1, i};
    if ( (int)s.size() >= n * 2 )
        return {0, i};

    s.insert(i);
    trio ans{0, i, q};
    for (int j = i; (!ans.t) && (j < n * 2); j++)
        if (s.find(j) == s.end()){
            s.insert(j);
            int idx;
            for (idx = 0; ; idx++)
                if (s.find(idx) == s.end())
                    break;
            int k = *(--s.find(j));
            if (s.upper_bound(j) == s.end())
                ans.t = f(idx, q - (a[j] - a[k]));
            else
                ans.t = f(idx, q);
            ans.j = j;
            ans.q = q - (a[j] - a[k]);
            s.erase(j);
        }
    s.erase(i);
    return ans;
}

int main(){
//    freopen("tests/02", "r", stdin);
    cin >> n >> k;
    a = new int[n*2];
    for (int i = 0; i < n * 2; i++)
        cin >> a[i];

    if (!f(0, k)){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0, j, q = k; (int)s.size() < n * 2; ){
        trio t = g(i, q);
        j = t.j, q = t.q;
        cout << i + 1 << " " << j + 1 << endl;
        s.insert(i), s.insert(j);
        for (i = i; (s.find(i) != s.end()) && (i < n * 2); i++);
    }
    return 0;
}
