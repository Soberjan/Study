#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

char a[3][20];

int minword(){
    int lst = 0;
    for (int i = 1; i < 3; i++)
        if (strcmp(a[i], a[lst]) < 0)
            lst = i;
    return lst;
}

int minfloat(){
    int dot[3] = {};
    char b[3][20];
    char c[3][20];
    int d[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; dot[i] == 0; j++)
            if (a[i][j]=='.')
                dot[i] = j;

    for (int i = 0; i < 3; b[i][dot[i]] = 0, i++)
        for (int j = 0; j < dot[i]; j++)
            b[i][j] = a[i][j];
    //cout << b[0] << ' ' << b[1] << ' ' << b[2];
    for (int i = 0; i < 3; i++)
        d[i] = (int)strlen(b[i]);

    for (int i = 0; i < 3; c[i][(int)strlen(a[i])] = 0, i++)
        for (int j = dot[i] + 1, z = 0; j < (int)strlen(a[i]) + 1; j++, z++)
            c[i][z] = a[i][j];
    //printf("%s\t%s\t%s\t", c[0], c[1], c[2]);

    int m = 0;
    for (int i = 1; i < 3; i++)
        if (d[i] < d[m])
            m = i;
        else if (d[i]==d[m]){
            if (strcmp(b[i], b[m]) < 0)
                m = i;
            else if (strcmp(b[i], b[m]) == 0)
                m = strcmp(c[i], c[m]) < 0 ? i : m;
        }
    return m;
}

int minint(){
    int m = 0;
    int d[3];
    for (int i = 0; i < 3; i++)
        sscanf(a[i], "%d", &d[i]);
    for (int i = 1; i < 3; i++)
        if (d[i] < d[m])
            m = i;
    return m;
}


int main()
{
    //freopen("tests/01", "r", stdin);

    while (scanf("%s\t%s\t%s", a[0], a[1], a[2]) != EOF) {
        bool isAl = 0, isFl = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; (j < (int)strlen(a[i])) && (!isAl) && (!isFl); j++)
                if ( (a[i][j] >= 65) && (a[i][j] <= 90) )
                    isAl = 1;
                else if (a[i][j] == '.')
                    isFl = 1;
            }

            int z = 0;
            if (isAl)
                z = minword();
            else if (isFl)
                z = minfloat();
            else
                z = minint();
            printf("%s\n", a[z]);
    }
    return 0;
}
