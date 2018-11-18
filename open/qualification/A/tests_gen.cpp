#include <iostream>
using namespace std;

void CreateTest(int i){
    int n = rand() % 15 + 1;
    int k = rand() % n;
    int x = rand() % 100;

    printf("%2d %2d %2d \n", n, k, x);
    printf("\n");
    int ans;
    scanf("%2d", &ans);

    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%2d %2d %2d \n", n, k, x);
    fclose(stdout);

    sprintf(buf, "tests\\%.2d.a", i);
    freopen (buf, "w", stdout);
    printf("%2d", ans);
    fclose(stdout);
    }


int main(){
    for (int i = 11; i < 12; i++)
        CreateTest(i);
    return 0;
    }
