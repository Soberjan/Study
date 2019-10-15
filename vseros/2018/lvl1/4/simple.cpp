#include <iostream>
using namespace std;

int n;

int main()
{
    //freopen("tests/04", "r", stdin);
    cin >> n;

    char *s = new char[n];
    if (n % 2 == 0)
        if (n/2%2 == 0){
            for (int i = 0; i < n / 2; i++)
                s[i] = s[n - i - 1] = i % 2 == 0 ? '+' : '-';
            for (int i = 0; i < n; i++)
                cout << s[i];
        }
        else
            cout << "IMPOSSIBLE";
    else if (n == 3)
        cout << "++-";
    else
        if ((n-1)/2%2 == 1){
            for (int i = 0; i < n / 2; i++)
                s[i] = s[n - i - 1] = i % 2 == 0 ? '+' : '-';
            s[n/2] = '+';
            for (int i = 0; i < n / 2; i++)
                if (n - i - 1 - i == n / 2 + 1)
                    s[n-i-1] = '-';
            for (int i = 0; i < n; i++)
                cout << s[i];
        }
        else cout << "IMPOSSIBLE";

    return 0;
}
