#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("tests/02", "r", stdin);

    string s, ans;
    cin >> s;
    s.pop_back();
    ans.resize((int)s.size());
    for (int q = 0, i = 0; q < (int)s.size(); q += 2, i++)
        ans[i] = s[q];
    for (int q = 1, i = (int)s.size() - 1; q < (int)s.size(); q += 2, i--)
        ans[i] = s[q];
    cout << ans;
    return 0;
}
