#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define X first
#define Y second

const int LIM = 100;
int x, y;

int n, m;
int a[LIM+3][LIM+3]{};
void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
pair<int, int> moves[8]{ {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
void f(){
    queue<pair<int,int>> s;
    s.push({0,0});
    a[0][0] = 1;
    while (s.size() != 0){
        pair<int, int> p = s.front();
        for (int i = 0; i < 8; i++)
            if ( ( p.X + moves[i].X >= 0) && (p.X + moves[i].X < n) && (p.Y + moves[i].Y >= 0) && (p.Y + moves[i].Y < m) && (a[p.X+moves[i].X][p.Y+moves[i].Y] == 0) )
                a[p.X+moves[i].X][p.Y+moves[i].Y] = a[p.X][p.Y]+1, s.push({p.X+moves[i].X, p.Y+moves[i].Y});
        s.pop();
    }
//    print();
}

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> x >> y;

    n = abs(x) + 3, m = abs(y) + 3;
    f();

    stack<pair<int, int>> ans;
    for (int x1 = abs(x), y1 = abs(y), q = a[x1][y1]; q > 1; q--)
        for (int i = 0; i < 8; i++)
            if (a[x1+moves[i].X][y1+moves[i].Y] == q - 1){
                ans.push({x1,y1});
                x1 += moves[i].X;
                y1 += moves[i].Y;
            }
    while (!ans.empty()){
        cout << (x < 0 ? -1 * ans.top().X : ans.top().X) << " " << (y < 0 ? -1 * ans.top().Y : ans.top().Y) << endl;
        ans.pop();
    }
    return 0;
}
