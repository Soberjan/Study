#include <iostream>
#include <deque>
#include <stack>
using namespace std;
#define X first
#define Y second

struct trio{
    int x, y, q;
    trio(int a, int b, int c) : x(a), y(b), q(c) {}
};
const int LIM = 100;
int a, b;


int c, d;
int e[LIM+3][LIM+3]{};
pair<int, int> moves[8]{ {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

void print(){
    for (int i = 0; i < c + 3; i++){
        for (int j = 0; j < d + 3; j++)
            cout << e[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void f(){
    deque<trio> s;
    s.push_front(trio(0,0,1));
    while (s.size() != 0){
        trio r = s.front();
        if ( (e[r.x][r.y] != 0) || (r.x < 0) || (r.x > c + 3) || (r.y < 0) || (r.y > d + 3) ){
            s.pop_front();
            continue;
        }
        e[r.x][r.y] = r.q;
        for (pair<int, int> p : moves)
            s.push_back(trio(r.x+p.X, r.y+p.Y, r.q+1));
        s.pop_front();
    }
//    print();
}

int main(){
    //freopen("tests/00", "r", stdin);

    cin >> a >> b;

    c = abs(a), d = abs(b);
    f();

    print();
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
