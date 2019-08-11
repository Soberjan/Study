#include <iostream>
#include <time.h>
using namespace std;

int main(int c, char** v){
//    srand(atoi(v[1]) + time(0));
//    int n = rand() % atoi(v[2]) + 1, m = rand() % atoi(v[3]) + 1, p = rand() % atoi(v[4]) + 10;
//    printf("%d %d %d\n", n, m, p);
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++)
//            printf("%3d", rand() % p);
//    printf("\n");
//    }
    for (int i = 10; i <= 100; i++)
        cout << i * 11 << " ";
    return 0;
    }
