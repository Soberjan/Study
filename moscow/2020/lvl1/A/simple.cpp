#include <iostream>
using namespace std;

int a, b, n, m;

int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> a >> b >> n >> m;

    int xmin = n + a * (n - 1);
    int ymin = m + b * (m - 1);
    int xmax = n + a * (n + 1);
    int ymax = m + b * (m + 1);

    if ( (xmin > ymax) || (ymin > xmax) )
        cout << -1;
    else
        cout << max(xmin, ymin) <<  " " << min(xmax, ymax);

    return 0;
}
