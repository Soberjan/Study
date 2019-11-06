#include <iostream>
#include <map>
using namespace std;
#define X first
#define Y second

int n;
map<int, pair<int, int>> dots;

int f(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    pair<int, int> ba = {b.X - a.X, b.Y - a.Y};
    pair<int, int> bc = {b.X - c.X, b.Y - c.Y};
    return (ba.X * bc.X + ba.Y * bc.Y == 0);
}

int main()
{
//    freopen("tests/01", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> dots[i].X >> dots[i].Y;

    int k = 0;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int q = j + 1; q < n; q++)
                k += f(dots[i], dots[j], dots[q]) + f(dots[i], dots[q], dots[j]) + f(dots[j], dots[i], dots[q]);

    cout << k;
    return 0;
}
