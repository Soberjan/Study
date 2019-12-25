#include <iostream>
using namespace std;
#define X first
#define Y second

const int LIM = 100;
int x, y;

int main(){
    //freopen("tests/01", "r", stdin);
    cin >> x >> y;

    int n = abs(x), m = abs(y);
    int i, j;
    for (i = 0, j = 0; ; ){
        if ( ( (i == n) && (j == m) ) || ( (i == n) && (j == m+1) ) || ( (i == n+1) && (j == m) ) || ( (i == n+1) && (j == m+1) ) )
            break;
        if (n - i < m - j)
            i+=1, j+=2;
        else
            i+=2, j+=1;
        cout << (x < 0 ? -1 * i : i) << " " << (y < 0 ? -1 * j : j) << endl;

    }

    if ( (i == n)   && (j == m) )
        cout << x << " " << y;
    if ( (i == n)   && (j == m+1) )
        cout << (x < 0 ? -1*(i+1) : i+1) << " " << (y < 0 ? -1*(j+2) : j+2) << endl << (x < 0 ? -1*(i+2) : i+2) << " " << (y < 0 ? -1* j    : j  ) << endl << x << " " << y;
    if ( (i == n+1) && (j == m) )
        cout << (x < 0 ? -1*(i+2) : i+2) << " " << (y < 0 ? -1*(j+1) : j+1) << endl << (x < 0 ? -1* i    : i  ) << " " << (y < 0 ? -1*(j+2) : j+2) << endl << x << " " << y;
    if ( (i == n+1) && (j == m+1) )
        cout << i+1 << " " << j-2 << endl << x << " " << y;
    return 0;
}
