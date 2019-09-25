#include <iostream>
using namespace std;

int m;

int main()
{
 //   freopen("tests/01", "r", stdin);
    cin >> m;
    if ((m < 3) || (m == 5))
        cout << 0 << "\n" << 0;
    else
        if (m % 3 == 0)
            cout << m / 3 << "\n" << 0;
        else if (m % 3 == 1)
            cout << (m - 4) / 3 << "\n" << 1;
        else if (m % 3 == 2){
            int s = 0;
            while (m % 3 != 0){
                m -= 4;
                s++;
            }
            cout << m / 3 << "\n" << s;
        }
    return 0;
}
