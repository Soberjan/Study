#include <iostream>
#include <time.h>
using namespace std;

const int NLIM = 10;

int main(){
    srand(time(0));
    int n = NLIM - rand() % (NLIM / 2);
    char ch = 'a';
    for (int i = 0; i < n; i++)
        cout << char(ch + rand() % 26);
    cout << '#';
    return 0;
    }
