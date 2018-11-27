#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct blocks{ int w, h; };

bool WayToSort(blocks a, blocks b){ return (a.w > b.w) || ((a.w == b.w) && (a.h > b.h)); }

int main()
{
    cin.tie(0);
    cout.tie(0);

    //freopen("tests/00", "r", stdin);
    int n;
    blocks a[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].w >> a[i].h;

    sort(a, a + n, WayToSort);
    long long s = a[0].h;
    for (int i = 1; i < n; i++)
        if ((a[i].w != a[i - 1].w))
            s += a[i].h;

    cout << s;
    return 0;
}
