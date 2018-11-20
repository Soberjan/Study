#include <iostream>
using namespace std;

void CreateTest(int i){
    int n = 1000000;
    char buf [50];
    sprintf(buf, "tests\\%.2d", i);
    freopen (buf, "w", stdout);
    printf("%d\n", n);
    for (int i = 0; i < n - 1; i++)
        printf("%c", 'a');
    printf("%c", 'b');
    fclose(stdout);
    }


int main(){
    CreateTest(10);
    return 0;
    }
