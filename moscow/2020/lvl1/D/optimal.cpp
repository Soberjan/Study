#include <iostream>
using namespace std;
#define X first
#define Y second

const int LIM = 100;
int x, y;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> x >> y;

    int u = (x > 0) - (x < 0), v = (y > 0) - (y < 0);
    int n = abs(x), m = abs(y);
    int i, j;
    for (i = 0, j = 0; ; ){
        if ( ( (i == n) && (j == m) ) || ( (i == n) && (j == m+1) ) || ( (i == n+1) && (j == m) ) || ( (i == n+1) && (j == m+1) ) )
            break;
        if (n - i < m - j)
            i+=1, j+=2;
        else
            i+=2, j+=1;
        cout << u * i << " " << v * j << endl;
    }

    if ( (i == n)   && (j == m) )
        cout << x << " " << y;
    if ( (i == n)   && (j == m+1) )
        cout << u * (i+1) << " " << v * (j+2) << endl << u * (i+2) << " " << v * j << endl <<     x << " " << y;
    if ( (i == n+1) && (j == m) )
        cout << u * (i+2) << " " << v * (j+1) << endl << u *  i << " " <<    v * (j+2) << endl << x << " " << y;
    if ( (i == n+1) && (j == m+1) )
        cout << u * (i+1) << " " << v * (j-2) << endl << x << " " << y;
    return 0;
}
