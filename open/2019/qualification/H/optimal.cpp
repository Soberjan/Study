#include <iostream>
#include <stdio.h>
#include <list>
#include<string>
using namespace std;

string s1, s2;

void print(int a[100], int len){
    cout << len << endl;
    for (int i = 0; i < len; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int ans[100];
void optimal(){
    int l[100], r[100];
    for(unsigned int i = 0; i < s1.size(); i++)
        l[i] = (s1[i] - '0');
    for(unsigned int i = 0; i < s2.size(); i++)
        r[i] = (s2[i] - '0');
    if (s.size() > s1.size()){
        ans[0] = r[0] - 1;
        for (int i = 1; i < s2.size(); i++)
            ans[i] = 9;
    } else {
        int i;
        for (int i = 0; l[i]==r[i]; ans[i] = r[i], i++)
            if (r[i])
                return ans = r;
        ans[i] = (r[i]==0) ? 0 : r[i-1];
        for (i = i + 1; i < r.s2.size(); i++)
            ans[i] = 9;
    }
}

int main()
{
    freopen("tests/03", "r", stdin);

    cin >> s1 >> s2;

    optimal();

    for (int i = 0; i < 100; i++)
        cout << ans[i];
    print(l, s1.size());
    print(r, s2.size());
    return 0;
}
