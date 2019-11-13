#include <iostream>
#include <vector>
#include <stack>
#include <bitset>
using namespace std;

int n, k;
vector<int> *u, *v;

inline bool g(int i, bitset<100001> &bs){
    for (int x : u[i])
        if (bs[x])
            return 1;
    return 0;
}

inline char f(int a, int b){
    stack<int> q;
    bitset<100001> bs1;
    bs1[100001] = 1;
    q.push(a);
    while (!q.empty()){
        int fst = q.top();
        q.pop();
        bs1[fst] = 1;
        for (int x : v[fst])
            if (!bs1[x])
                q.push(x);
    }
    if (bs1[b])
        return '+';
    bitset<100001> bs2;
    bs2[100001] = 1;
    q.push(b);
    while (!q.empty()){
        int fst = q.top();
        q.pop();
        bs2[fst] = 1;
        for (int x : v[fst])
            if (!bs2[x])
                q.push(x);
    }
    for (int i = bs1._Find_first(); i < 100001; i = bs1._Find_next(i))
        if ((bs1[i]) && g(i, bs2))
            return '-';
    return '?';
}

int main(){
//    freopen("tests/01", "r", stdin);
    cin >> n >> k;
    v = new vector<int>[n];
    u = new vector<int>[n];

    for (int i = 0; i < k; i++){
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '+')
            v[a-1].push_back(b-1), v[b-1].push_back(a-1);
        if (c == '-')
            u[a-1].push_back(b-1), u[b-1].push_back(a-1);
        if (c == '?')
            cout << f(a-1, b-1) << "\n";
    }


    return 0;
}
