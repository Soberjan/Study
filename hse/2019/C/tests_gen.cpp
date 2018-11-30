#include <iostream>
#include <time.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

void CreateTest(int i){
    int n = rand() % 25 + 5;
    int h = rand() % n + 1;
    int f = rand() % n + 1;
    int a[110];
    for (int j = 0; j < h; j++)
        a[j] = rand() % n + 1;
    sort(a, a + h);
    printf("%d %d %d \n", n, h, f);
    printf("\n");
    for (int j = 0; j < h; j++)
        printf("%d ", a[j]);
    printf("\n");
    int ans;
    scanf("%2d", &ans);

    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%d %d %d \n", n, h, f);
    printf("\n");
    for (int j = 0; j <h; j++)
        printf("%d ", a[j]);
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
