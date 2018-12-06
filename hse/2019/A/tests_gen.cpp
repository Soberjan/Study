#include <iostream>
#include <time.h>
using namespace std;

void CreateTest(int i){
    int n = 1000000000;
    int p = rand() % n + 1;
    int q = rand() % n + 1;
    char buf [50];
 
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%d %d %d\n", n, p, q);
    fclose(stdout);       
    }

int main(){
    srand(time(0));
    for (int i = 10; i < 15; i++)
        CreateTest(i);
    return 0;
    }
