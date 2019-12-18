#include <iostream>
using namespace std;
#define X first
#define Y second

int s = 1e4;
int n, m, q;
int *a, *d;
pair<int, int> *cb;

int main()
{
    freopen("tests/01", "r", stdin);
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    cb = new pair<int, int>[m];
    for (int i = 0; i < m; i++)
        cin >> cb[i].X >> cb[i].Y;
    cin >> q;
    d = new int[q];
    for (int i = 0; i < q; i++)
        cin >> d[i];


    return 0;
}
