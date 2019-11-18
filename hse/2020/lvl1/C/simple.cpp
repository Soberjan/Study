#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int n, k;
vector<int> *u, *v;

inline char f(int a, int b){
    stack<int> q;
    set<int> s1;
    q.push(a);
    while (!q.empty()){
        int fst = q.top();
        q.pop();
        s1.insert(fst);
        for (int x : v[fst])
            if (s1.find(x) == s1.end())
                q.push(x);
    }
    if (s1.find(b) != s1.end())
        return '+';
    set<int> s2;
    q.push(b);
    while (!q.empty()){
        int fst = q.top();
        q.pop();
        s2.insert(fst);
        for (int x : v[fst])
            if (s2.find(x) == s2.end())
                q.push(x);
    }
    for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it)
        for (int x : u[*it])
            if (s2.find(x) != s2.end())
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
