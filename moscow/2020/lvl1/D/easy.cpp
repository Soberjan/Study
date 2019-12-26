#include <iostream>
#include <deque>
using namespace std;
#define X first
#define Y second
const int LIM = 100;

int a, b;
int c, d;
int e[LIM+3][LIM+3]{};

pair<int, int> moves[8]{ {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
void f(int x, int y, int z){
    if ( (e[x][y] != 0) || (x < 0) || (x > c + 2) || (y < 0) || (y > d + 2) )
        return;
    e[x][y] = z;
    if ( (x == c) && (y == d) )
        return;
    for (pair<int, int> p : moves)
        f(x+p.X, y+p.Y, z+1);
}

int main(){
//    freopen("tests/00", "r", stdin);
    cin >> a >> b;

    c = abs(a), d = abs(b);
    f(0, 0, 1);

    deque<pair<int, int>> ans;
    for (int x = c, y = d, q = e[x][y]; q > 1; q--)
        for (pair<int, int> p : moves)
            if (e[x+p.X][y+p.Y] == q - 1){
                ans.push_front({x,y});
                x += p.X, y += p.Y;
                break;
            }
    int u = (a > 0) - (a < 0), v = (b > 0) - (b < 0);
    for (pair<int, int> p : ans)
        cout << u * p.X << " " << v * p.Y << endl;
    return 0;
}
