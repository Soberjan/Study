#include <iostream>
#include <time.h>
using namespace std;

void CreateTest(int i){
    int n = 3;
    int p = rand() / 100;
    int k = rand() / 20;
    int a[10];
    for (int j = 0; j < n; j++)
        a[j] = rand() / 30;

    printf("%d %d %d \n", n, p, k);
    for (int j = 0; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");
    int ans;
    scanf("%d", &ans);
    printf("\n");

    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%d %d %d \n", n, p, k);
    for (int j = 0; j < n; j++)
        printf("%d ", a[j]);
    fclose(stdout);

    sprintf(buf, "tests\\%.2d.a", i);
    freopen (buf, "w", stdout);
    printf("%d", ans);
    fclose(stdout);
    }

void CreateTest1(int i){
    int n = 100000;
    long long p = 1000000000000000000;
    int k = 1000000000;
    int a[100000];
    for (int j = 0; j < n; j++)
        a[j] = 1;

    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    cout << n << " " << p << " " << k << "\n";
    for (int j = 0; j < n; j++)
        cout << a[j] << " ";
    fclose(stdout);
    }


int main(){
    srand(time(0));
//    for (int i = 7; i < 9; i++)
//        CreateTest(i);
    CreateTest1(10);
    return 0;

    }
