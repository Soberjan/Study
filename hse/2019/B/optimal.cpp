#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

void fix_time(int& h, int& minutes, int& days) {
    h += minutes / 60;
    minutes = minutes % 60;
    days += h / 24;
    h = h % 24;
}

int main()
{
    //freopen("tests/02", "r", stdin);
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int s = 0, num = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > a[i - 1])
            num = 0;
        num += 1;
        if (a[i] == num){
            s += num;
            num = 0;
        }
    }

    cout << s;
    return 0;
}