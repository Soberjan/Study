#include <iostream>
#include <map>
#include <set>
#include <bitset>
using namespace std;
#define X first
#define Y second
const int NLIM = 10;

struct walker{ int i, j, q; };
bool operator<(const walker& l, const walker& r){ return ( (l.j < r.j) ) || ( (l.j == r.j) && (l.q >= r.q) ); }

int k, n, m, u, v, l;
map<int, set<pair<int, int> > > ms;
bitset<NLIM> a;

inline void f(set<walker> &s, map<int, set<walker>> &m, pair<int,int> neib, walker wadd){
    if ((wadd.i == v) && (wadd.q >= 0)){
        m[v].insert(wadd);
        return ;
    }
    if (wadd.q <= 0)
        return;

    int add = 1; // 0 - не добавляем 1 - добавляем 2 - заменяем
    for(set<walker>::iterator it = m[neib.X].begin(); it != m[neib.X].end(); ++it)
        if ( (wadd.j >= (*it).j) && (wadd.q <= (*it).q) ){
            add = 0;
            break;
        }
        else if ( (wadd.j == (*it).j) && (wadd.q > (*it).q) ){
            m[neib.X].erase(it);
            add = 2;
            break;
        }
    if (add != 0)
        m[neib.X].insert(wadd), s.insert(wadd);
}

int main(){
//    freopen("tests/06", "r", stdin);
    cin >> k >> n >> m >> u >> v;
    for (int i = 0; i < m; i++){
        int p, q, r;
        cin >> p >> q >> r;
        ms[p].insert({q, r});
        ms[q].insert({p, r});
    }
    cin >> l;
    for (int i = 0; i < l; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }

    set<walker> s; s.insert(walker{u, 0, k});
    map<int, set<walker>> m; m[u].insert(walker{u, 0, k});
    while ( (m[v].empty()) && (!s.empty()) ){
        set<walker>::iterator w = s.begin();
 //       cout << "QUEUE: " << (*w).i << " " << (*w).j << " " << (*w).q << "\n";
        for (auto neib : ms[(*w).i]){
            walker wadd{neib.X, (*w).j, (*w).q-neib.Y};

//            cout << "  ADD: " << wadd.i << " " << wadd.j << " " << wadd.q << " " << neib.X << " " << neib.Y << "\n";
            f(s, m, neib, wadd);
            if ((a[neib.X]) && (wadd.q >= 0)){
                wadd.j++, wadd.q = k, f(s, m, neib, wadd);
//                cout << "       " << wadd.i << " " << wadd.j << " " << wadd.q << " " << neib.X << " " << neib.Y << "\n";
            }
        }
        s.erase(w);
    }

    cout << ( m[v].empty() ? -1 : ( * ( m[v].begin() ) ) .j );

    return 0;
}
