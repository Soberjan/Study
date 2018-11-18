#include <iostream>
#include <algorithm>

using namespace std;

int n, q, a[40];

void simple(){
    for (int i = 0; i < q; i++){
        char c;
        int x, y;
        cin >> c >> x >> y;

        x -= 1;
        if (c == '!')
            a[x] = y;

        int b[40];
        if (c == '?'){
            for (int j = x; j < y; j++)
                b[j] = a[j];
            sort(b + x, b + y);
            int c = 0;
            for (int j = x; j < y; j++)
                if (b[j] == c)
                    c += 1;
            cout << c << "\n";
            }
        }
    }
int main()
{
    //freopen("tests\\05", "r", stdin);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    simple();
    return 0;
}
