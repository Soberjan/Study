#include <iostream>
using namespace std;

int n;

int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> n;

    if ((n % 2 == 0) || (n == 1))
        cout << "IMPOSSIBLE";
    else{
        char s[n];
        for (int i = 0; i < n / 2; i++)
            s[i] = s[n - i - 1] = i % 2 == 0 ? '+' : '-';
        s[n/2] = '+';
        s[n/2-1] = s[n/2+1] = '-';
        for (int i = 0; i < n / 2; i++)
            if (n - i - 1 - i - 1 == n / 2){
                s[i] = '+';
                s[n-i-1] = '-';
            }
        for (int i = 0; i < n; i++)
            cout << s[i];
    }

    return 0;
}
