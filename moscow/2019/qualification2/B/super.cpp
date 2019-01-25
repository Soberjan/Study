#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

string b[3];
string a;
int minWord(){
    int lst = 0;
    for (int i = 1; i < 3; i++)
        if (b[i].compare(b[lst]) < 0)
            lst = i;
    return lst;
}

int minFl(){
    long double dl[3];
    for (int i = 0; i < 3; i++)
        dl[i] = stold(b[i], 0);
    int lst = 0;
    for (int i = 1; i < 3; i++)
        if (dl[i] < dl[lst])
            lst = i;
    return lst;
}

int minInt(){
    long long ll[3];
    for (int i = 0; i < 3; i++)
        ll[i] = stoll(b[i], 0, 0);
    int lst = 0;
    for (int i = 1; i < 3; i++)
        if (ll[i] < ll[lst])
            lst = i;
    return lst;
}

int main ()
{
    //freopen("tests/01", "r", stdin);

    while (getline(cin, a)){
        istringstream str(a);
        for (int i = 0; i < 3; i++)
            getline(str, b[i], '\t');
//        for (int i = 0; i < 3; i++)
//            cout << b[i] << ' ';
//        cout << '\n';
        bool isAl = 0, isFl = 0;
        for (int i = 0; ( (i < (int)a.size()) && (!isAl) && (!isFl) ); i++){
            if (isalpha(a[i]))
                isAl = 1;
            if (a[i] == '.')
                isFl = 1;
        }
        int idx;
        if (isAl)
            idx = minWord();
        else if (isFl)
            idx = minFl();
        else
            idx = minInt();

        cout << b[idx] << '\n';
        }

    return 0;
}
