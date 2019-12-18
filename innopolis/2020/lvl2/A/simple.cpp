#include <iostream>
#include <set>
using namespace std;

string s;

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> s;
    set<char> m {'+', '-', '/', '*'};
    int n = (int)s.size();
    for (int i = 0; i < n - 1; i++){
        cout << s[i];
        if (m.find(s[i+1]) != m.end())
            cout << ' ';
        if (m.find(s[i]) != m.end())
            cout << ' ';
    }
    cout << s[n-1];

    return 0;
}
