#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
int n, q, a[500000];
void simple(){
    for (int i = 0; i < q; i++){
        char c;
        int x, y;
        cin >> c >> x >> y;

        x -= 1;
        if (c == '!')
            a[x] = y;

        char b[500000] = {};
        if (c == '?'){
            for (int j = x; j < y; j++)
                b[a[j]] = 1;
            int num = 0;
            for (int j = 0; j < n; j++)
                if (b[j] != 1){
                    num = j;
                    break;
                }
            cout << num << "\n";
            }
        }
    }
int main()
{
    //freopen("tests\\01", "r", stdin);
    //    cin.tie(0);
//    cout.tie(0);
//    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    simple();
    return 0;
}
