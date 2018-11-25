#include <iostream>
#include <time.h>
using namespace std;

void simpe(int n, int p, int q){
    int minim = 0;
    int maxim = 0;
    int a = p - 1;
    int d = n - q;
    int r = d - a;
    if (r > 0){
        minim = 1;
        maxim = max(p, q);
    }
    if (r == 0){
        minim = 1;
        maxim = n;
    }
    if (r < 0){
        minim = a - d + 1;
        maxim = n;
    }
    if ((p == 1) || (q == 1)){
        minim = 1;
        maxim = p = 1 ? q : p;
    }
    if ((p == n) || (q == n)){
        minim = p = n ? q : p;
        maxim = n;
    }

    printf("%d %d\n", minim, maxim);
}

void CreateTest(int i){
    int n = rand() % 100 + 1;
    int p = rand() % n + 1;
    int q = 100 - rand() % p;
    char buf [50];
    printf("%d %d %d\n",n, p, q);
    system("pause");
    simpe(n, p, q);

    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%d %d %d\n", n, p, q);
    fclose(stdout);

    sprintf(buf, "tests\\%.2d.a", i);
    freopen (buf, "w", stdout);
    simpe(n, p, q);
    fclose(stdout);
    system("pause");
    }


int main(){
    srand(time(0));
    for (int i = 7; i < 10; i++)
        CreateTest(i);
    return 0;
    }
