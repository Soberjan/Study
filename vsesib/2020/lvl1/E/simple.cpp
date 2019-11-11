#include <iostream>             
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define f(x, y) (m + 2) * (x + 1) + (y + 1)
#define fst que.front()
#define X first
#define Y second

int n, m, q, S;
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

vector<int>* fk(int num){
    vector<int> *A = new vector<int>[num - 1];
    for (int i = 0; i < q; i++)
        if (b[i].X < 0){
            if (a[b[i].Y-1] != -1){
                A[a[b[i].Y]-1].push_back(a[b[i].Y-1] - 1);
                A[a[b[i].Y-1]-1].push_back(a[b[i].Y]-1);
            }
            if (a[b[i].Y+1] != -1){
                A[a[b[i].Y]-1].push_back(a[b[i].Y+1] - 1);
                A[a[b[i].Y+1] - 1].push_back(a[b[i].Y]-1);
            }
            if (a[b[i].Y - (m + 2)] != -1){
                A[a[b[i].Y]-1].push_back(a[b[i].Y-(m + 2)] - 1);
                A[a[b[i].Y-(m + 2)] - 1].push_back(a[b[i].Y]-1);
            }
            if (a[b[i].Y + (m + 2)] != -1){
                A[a[b[i].Y]-1].push_back(a[b[i].Y+(m + 2)] - 1);
                A[a[b[i].Y+(m + 2)] - 1].push_back(a[b[i].Y]-1);
            }
        }
    return A;
}

int e(vector<int> *A, vector<int>& v, int c, int s){
    bitset<19> blocked_nodes(c);
    queue<int> que;
    que.push(s);
    int sum = 0;
    while (!que.empty()){
        sum += v[fst];
        for (int i : A[fst])
            if (!blocked_nodes[i])
                que.push(i);
        blocked_nodes[fst] = 1;
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
    S = f(x - 1, y - 1);
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

    int num = 1;
    vector<int> v;
    for (int i = 0; i < q; i++)
        if (b[i].X < 0){
            v.push_back(b[i].X);
            a[b[i].Y] = num++;
        }
    for (int i = 0; i < k; i++)
        if (a[i] == 0)
            v.push_back(g(i, num++));
    vector<int> *A = fk(num);
    int m = 0, s = a[S];
    int n_a = 0;
    for (int i : v)
        n_a += (i > 0);
    n_a = 1 << n_a;
    for (int c = 0;  c <= n_a; c++)
        m = max(e(A, v, c, s), m);
    cout << m;
    return 0;
}
//    print(k);
//    cout << "\n\n";
//    for (int x : v)
//        cout << x << " ";
//    cout << "\n\n";
//    for (int i = 0; i < num; i++){
//        for (int x : A[i])
//            cout << x << " ";
//        cout << "\n";
//    }

