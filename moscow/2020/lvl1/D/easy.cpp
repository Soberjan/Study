#include <iostream>
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
void f(int x, int y){
    for (int i = 0; i < 8; i++)
        if ( ( x + moves[i].X >= 0) && (x + moves[i].X < n) && (y + moves[i].Y >= 0) && (y + moves[i].Y < m) && (a[x+moves[i].X][y+moves[i].Y] == 0) )
            a[x+moves[i].X][y+moves[i].Y] = a[x][y]+1, f(x+moves[i].X, y+moves[i].Y);
}

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> x >> y;

    n = abs(x) + 3, m = abs(y) + 3;
    a[0][0] = 1;
    f(0, 0);

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
