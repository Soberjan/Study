#include <iostream>
#include <vector>
#include <stack>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(x, y) (m + 2) * (x + 1) + (y + 1)
#define X first
#define Y second

int n, m, q, st, *a, *pos, *T;
pair<int, int> *b;
vector<int> *S;

void g(int i, int v){
    stack<int> s({i});
    while (!s.empty()){
        int fst = s.top();
        a[fst] = v;
        s.pop();
        for (int i = 0; i < 4; i++)
            if (a[fst+pos[i]] == -1)
                s.push(fst+pos[i]);
    }
}

int BFS(int st, int c){
    bitset<100> bs(c);
    stack<int> s({st});
    int sum = 0;
    while (!s.empty()){
        int fst = s.top();
        sum += T[fst];
        bs[fst] = 1;
        s.pop();
        for (int x : S[fst])
            if (bs[x] != 1)
                s.push(x);
    }
    return sum;
}

void print(){
    char buf[3];
    for (int i = 0; i < (n + 2) * (m + 2); i++){
        int j = i;
        sprintf(buf, "%3d", a[j]);
        cout << ((i % (m + 2) == 0) ? "\n" : "")  << buf;
    }
}

int main(){
    freopen("tests/00", "r", stdin);
    cin >> n >> m >> q;
    int x, y;
    cin >> x >> y;
    st = f(x - 1, y - 1);
    int k = (n + 2) * (m + 2);
    a = new int[k];
    b = new pair<int, int>[q];
    fill(a, a + k, -2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char c;
            cin >> c;
            a[f(i, j)] = c == '.' ? -1 : -2;
        }
    for (int i = 0; i < q; i++){
        cin >> x >> y >> b[i].first;
        b[i].Y = f(x - 1, y - 1);
    }

    sort (b, b + q);
    int u;
    for (u = 0; b[u].X < 0; u++)
        a[b[u].Y] = u;
    int v = u;
    pos = new int[4]{-1,-m-2,1,m+2};
    for (int i = 0; i < k; i++)
        if (a[i] == -1)
            g(i, v++);

    S = new vector<int>[v];
    for (int i = 0; i < u; i++)
        for (int j = 0; j < 4; j++)
        if (a[b[i].Y+pos[j]] != -2)
            S[i].push_back(a[b[i].Y+pos[j]]), S[a[b[i].Y+pos[j]]].push_back(i);
    T = new int[v]{};
    for (int i = 0; i < q; i++)
        T[a[b[i].Y]] += b[i].X;

    int mx = 0;
    st = a[st];
    for (int i = 0; i < (1 << v); i++)
        mx = max(mx, BFS(st, i));
    cout << mx;
//    print();
//    cout << "\n";
//    for (int i = 0; i < v; i++){
//        cout << i << " : " << T[i] << " : ";
//        for (int j : S[i])
//            cout << j << " ";
//        cout << "\n";
//    }
    return 0;
}
