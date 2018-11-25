#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

void CreateTest(int i){
    int n = rand() % 100;
    int h = rand() % 40;
    int f = rand() % n;
    int a[110];
    for (int j = 0; j < n; j++)
        a[j] = rand() % 100;
    printf("%2d %2d %2d \n", n, h, f);
    printf("\n");
    for (int j = 0; j < n; j++)
        printf("d ", a[j]);
    printf("\n");
    int ans;
    scanf("%2d", &ans);

    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%2d %2d %2d \n", n, h, f);
    printf("\n");
    for (int j = 0; j < n; j++)
        printf("d ", a[j]);
    fclose(stdout);

    sprintf(buf, "tests\\%.2d.a", i);
    freopen (buf, "w", stdout);
    printf("%2d", ans);
    fclose(stdout);
    }

int main(){
    srand(time(0));
    for (int i = 11; i < 12; i++)
        CreateTest(i);
    return 0;
    }
