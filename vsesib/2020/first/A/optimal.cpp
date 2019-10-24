#include <iostream>
#include <algorithm>
using namespace std;
#define X first
#define Y second


int n, *s;
long long k, t;

int main()
{
//    freopen("tests/01", "r", stdin);
    cin >> n >> k >> t;
    s = new int[n];
    for (int i = 0; i < n; i++){
        char e; int a, b;
        cin >> a >> e >> b;
        s[i] = a * b;
    }

    sort(s, s + n);
    pair<long long, int> p;
    long long b = 0;
    if (k < t){
        p = {k, 0};
        b = t;
    }
    else{
        p = {t, 0};
        b = k;
    }
    int q = 0;
    for (int i = 0; i < n; i++){
        long long z = s[i] - p.Y;
        if (z <= 0){
            p.Y = p.Y * (-1);
        }
        else{
            int m = ceil((double)z / b);
            p.X = p.X - m;
            p.Y = b - z % b;
        }
        if ((p.X >= 0) && (p.Y >= 0))
            q++;
        else
            break;
    }

    cout << q;
    return 0;
}
