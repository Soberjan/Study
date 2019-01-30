#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char* minint(char l[100], char r[100]){
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

char* min (char l[100], char r[100]){
    int dot = 0, alp = 0;
    for (int i = 0; i < (int)strlen(l); i++){
        dot = dot || (l[i] == '.');
        alp = alp || (isalpha(l[i]));
    }
    if (alp)
        return (strcmp(l, r) < 0) ? l : r;
    if (!dot)
        return (minint(l, r));

}

int main(){
    //freopen("tests/01", "r", stdin);
    char a[100], b[100], c[100];
    while (cin >> a >> b >> c){
        cout << a << " " << b << " " << c << "\n";
        cout << min(min(a, b), c);
    }

    return 0;
}
