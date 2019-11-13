#include <iostream>
#include <map>
using namespace std;
#define X first
#define Y second


int n, k;
int **a;

int main()
{
    freopen("tests/00", "r", stdin);
    cin >> n >> k;
    multimap<int, pair<int, int>> m;
    a = new int*[2];
    a[0] = new int[n];
    a[1] = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[0][i] >> a[1][i];
        m.insert({a[0][i], {0, i}});
        m.insert({a[1][i], {1, i}});
    }
    int **c = new int*[2];
    c[0] = new int[n]{};
    c[1] = new int[n]{};
    for (multimap<int, pair<int, int>>::iterator it = m.begin(); it != m.end(); ++it)
        cout << it.X << " " << it.Y.X << " " << it.Y.Y << "\n";
    return 0;
}
