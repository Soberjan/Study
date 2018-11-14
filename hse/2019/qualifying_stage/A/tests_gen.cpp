#include <iostream>
using namespace std;

void CreateTest(int i, int n, int k){
    int a[20];
    for (int j = 0; j < n; j++)
        a[j] = rand() % 10;

    printf("%2d %2d \n", n, k);
    for (int j = 0; j < n; j++)
        printf("%2d ", a[j]);
    printf("\n");
    int ans;
    scanf("%2d", ans);



//    freopen (sprintf("tests\\0%.2d", [i]), "w", stdout);
    printf("%2d %2d \n", n, k);
    for (int j; j < n; j++)
        printf("2d ", a[j]);
    fclose(stdout);

   // freopen (sprintf("tests\\0%.2d.a", [i]), "w", stdout);
    printf("%2d", ans);
    fclose(stdout);
    }


int main(){
    for (int i = 1; i < 4; i++){
        int n = rand() % 15 + 1;
        int k = rand() % 10;
        //CreateTest(i, n, k);
    }

    char buf [50];

    int a, b, n;
    n = spintf (buf, "%2d 1 %d", [a], [b]);


    return 0;
    }
