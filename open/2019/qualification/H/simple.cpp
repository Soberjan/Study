#include <iostream>
#include <stdio.h>
using namespace std;

int l, r;

int simple(){
    int a[100], x = l;
    for (int i = l, s = 1, s2 = 1; i <= r; i++, s2 = 1){
        int b = i, c = 0;
        while (b != 0){
            a[c] = b % 10;
            b = b / 10;
            c++;
        }
        for (int j = 0; j < c; j++)
            s2 *= a[j];
        if (s2 >= s){
            s = s2;
            x = i;
        }
    }
    return x;
}

int main()
{
//    freopen("tests/04", "r", stdin);
    cin >> l >> r;

    cout << simple();

    return 0;
}
