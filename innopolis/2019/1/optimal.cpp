#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int x, y;

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> x >> y;
    int k = max(x, y);
    int snd = 0;
    int fst;
    for (fst = 1; fst <= x; fst++){
        cout << fst << ":" << snd << '\n';
        if (snd < y){
        for (++snd; snd <= fst; snd++)
            cout << fst << ":" << snd << '\n';
        snd--;
        }
    }
    fst--;
    for (snd++; snd <= y; snd++)
        cout << fst << ":" << snd << '\n';

    return 0;
}
