#include <iostream>
#include <time.h>
using namespace std;

void CreateTest(int i){
    int n = 100000;
    int a[100000];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 30000 + rand() % 30000 + rand() % 30000;
    char buf [50];

    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    fclose(stdout);
    }

int main(){
    srand(time(0));
    for (int i = 10; i < 15; i++)
        CreateTest(i);
    return 0;
    }
