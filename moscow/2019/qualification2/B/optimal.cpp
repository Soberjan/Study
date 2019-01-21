#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
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
    int b[3];
    int c[3][20];
    for (int i = 0; i < 3; i++)
        for (int j = 0; dot[i] == 0; j++)
            if (j=='.')
                dot[i] = j;

    for (int i = 0; i <3; i++)
        sscanf(a[i].substr(0, strlen(a[i]) - dot[i]), "%d", b[i]);

    for (int i = 0; i < 3; i++)
        for (int j = dot[i]+1; j < strlen(a[i]); j++)
            sscanf(a[i], "%d", c[i][j]);

    int m = 0;
    for (int i = 1; i < 3; i++)
        if (b[i] < b[m])
            m = 0;
        else if (b[i]==b[m])
            if(strcmp(c[i], c[m]) < 0)
                m = i;

    return m;
}

int minint(){
    int m = 0;
    for (int i = 1; i < 3; i++)
        if (a[i] < a[m])
            m = i;
    return m;
}


int main()
{
    freopen("tests/00", "r", stdin);

    int q;
    while (q != EOF) {
        q = scanf("%s\t%s\t%s", a[0], a[1], a[2]);
        //printf("%d\t%d\t%d\n", strlen(a[0]), strlen(a[1]), strlen(a[2]));
        for (int i = 0; i < 3; i++){
            bool isAl = 0, isFl = 0;
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

        //printf("%s\t%s\t%s\t%d\n", a[0],a[1], a[2], q);
    return 0;
}
