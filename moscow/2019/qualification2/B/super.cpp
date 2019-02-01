#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string minint(string l, string r){
    bool ms1 = 0, ms2 = 0;
    ms1 = l[0] == '-' ? 1 : 0;
    ms2 = r[0] == '-' ? 1 : 0;
    if (ms1 && ms2)
        return minint(l + 1, r + 1);
    if (ms1 || ms2)
        return ms1 == 1 ? l : r;

    if ((int)strlen(l) == (int)strlen(l))
        return strcmp(l, r) < 0 ? l : r;

    return (int)strlen(l) < (int)strlen(l) ? l : r;
}

string d;
string min (string l, string r){
    bool alp = 0;
    for (unsigned int i = 0; i < d.size(); i++)
        alp = alp || (isalpha(l[i]));

    if (alp)
        return strcmp(l, r) < 0 ? l : r;

    if (l.find('.') == npos)
        return minint(l, r);

}

int main(){
    //freopen("tests/01", "r", stdin);
    string a, b, c;
    while (cin >> a >> b >> c){
        d = a + b + c;
        cout << min(min(a, b), c);
    }

    return 0;
}
