#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define f(x, y) (m + 2) * (x + 1) + (y + 1)
#define fst que.front()
#define X first
#define Y second

int n, m, q, s;
pair<int, int> *b;
int *a;

void h(queue<int>& que, int c){
    if (a[c - 1] == 0)
        que.push(c - 1);
    if (a[c + 1] == 0)
        que.push(c + 1);
    if (a[c - (m + 2)] == 0)
        que.push(c - (m + 2));
    if (a[c + (m + 2)] == 0)
        que.push(c + (m + 2));
}

int i(int c){
    for (int i = 0; i < q; i++)
        if (b[i].Y == c)
            return b[i].X;
    return 0;
}

int g(int c, int n){
    int sum = 0;
    queue<int> que;
    que.push(c);
    while (!que.empty()){
        h(que, fst);
        sum += i(fst);
        a[fst] = n;
        que.pop();
    }

    return sum;
}

void print(int k){
    for (int i = 0; i < k; i++)
        if (i % (m + 2) == 0)
            printf("\n%3d ", a[i]);
        else
            printf("%3d ", a[i]);
}

int main(){
    freopen("tests/00", "r", stdin);
    cin >> n >> m >> q;
    int x, y;
    cin >> x >> y;
    s = f(x - 1, y - 1);
    int k = (n + 2) * (m + 2);
    a = new int[k];
    b = new pair<int, int>[q];
    fill(a, a + k, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char c;
            cin >> c;
            a[f(i, j)] = c == '.' ? 0 : -1;
        }
    for (int i = 0; i < q; i++){
        cin >> x >> y >> b[i].first;
        b[i].Y = f(x - 1, y - 1);
    }

    for (int i = 0; i < q; i++)
        a[b[i].Y] = b[i].X < 0 ? -1 : 0;
    int num = 1;
    vector<int> v;
    for (int i = 0; i < k; i++)
        if (a[i] == 0)
            v.push_back(g(i, num++));
    print(k);
    cout << "\n\n";
    for (int x : v)
        cout << x << " ";
    return 0;
}
