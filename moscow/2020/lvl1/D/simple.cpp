#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define X first
#define Y second

int x, y;

int n, m;
pair<int, int> **a;
void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j].X << ":" << a[i][j].Y << " ";
        cout << endl;
    }
    cout << endl;
}
void g(int i, int j, pair<int, int> p, queue<pair<int,int>> &s){
        if ( (i >= 0) && (i < n) && (j >= 0) && (j < n) && (a[i][j] == make_pair(-1,-1)) )
            a[i][j] = p, s.push({i, j});
}
void f(){
    queue<pair<int,int>> s;
    s.push({0,0});
    a[0][0] = {0, 0};
    while (s.size() != 0){
        pair<int, int> p = s.front();
        g(p.X-1, p.Y+2, p, s);
        g(p.X+1, p.Y+2, p, s);
        g(p.X+2, p.Y+1, p, s);
        g(p.X+2, p.Y-1, p, s);
        g(p.X+1, p.Y-2, p, s);
        g(p.X-1, p.Y-2, p, s);
        g(p.X-2, p.Y-1, p, s);
        g(p.X+2, p.Y+1, p, s);
        //print();
        s.pop();
    }
}

int main(){
    freopen("tests/00", "r", stdin);
    cin >> x >> y;

    n = abs(x) + 3, m = abs(y) + 3;
    a = new pair<int, int>*[n];
    for (int i = 0; i < n; i++){
        a[i] = new pair<int, int>[m];
        fill(a[i], a[i] + m, make_pair(-1, -1));
    }

    f();


    stack<pair<int, int>> s;
    s.push({abs(x), abs(y)});
    a[0][0] = {-1, -1};

    pair<int, int> p = a[abs(x)][abs(y)];
    while (p != make_pair(-1, -1)){
        s.push(p);
        p = a[p.X][p.Y];
    }
    s.pop();
    while (!s.empty()){
        cout << ( x < 0 ? -1 * s.top().X : s.top().X ) << " " << ( y < 0 ? -1 * s.top().Y : s.top().Y ) << endl;
        s.pop();
    }


    return 0;
}
