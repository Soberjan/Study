#include <iostream>
using namespace std;

void CreateTest(int i){
    int n = rand() % 20;
    int p = rand() % 50;
    int k = rand() % 30;
    int a[50];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 20;

    printf("%2d %2d %2d \n", n, p, k);
    for (int i = 0; i < n; i++)
        printf("%2d", a[i]);
    printf("\n");
    int ans;
    scanf("%2d", &ans);
    printf("\n");

    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%2d %2d %2d \n", n, p, k);
    for (int i = 0; i < n; i++)
        printf("%2d ", a[i]);
    fclose(stdout);

    sprintf(buf, "tests\\%.2d.a", i);
    freopen (buf, "w", stdout);
    printf("%2d", ans);
    fclose(stdout);
    }


int main(){
    for (int i = 2; i < 6; i++)
        CreateTest(i);
    return 0;
    }
