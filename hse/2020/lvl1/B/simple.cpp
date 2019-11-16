#include <iostream>
#include <cstring>
using namespace std;
#define X first
#define Y second

int n, k, smax;
pair<int, int> *a, *b;

void print(pair<int, int> *c){
    for (int i = 0; i < n; i++)
        cout << c[i].X << " " << c[i].Y << "\n";
}

void f(int p, int q, int s, pair<int, int> *c){

    for (int i = p; i <= k; i++){
        c[i].X = c[i].Y = q;
        s += (a[i].X + a[i].Y);
        if (s > smax)
            memcpy(b, c, sizeof(pair<int, int>) * n), smax = s;
        print(c);
        cout << s << " " << smax << "\n\n";
        f(i + 1, q+1, s, c);
        c[i].X = c[i].Y = 0;
        s -= a[i].X + a[i].Y;
    }
}

int main(){
    freopen("tests/02", "r", stdin);
    cin >> n >> k;
    a = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;

    b = new pair<int, int>[n];
    pair<int, int> *c = new pair<int, int>[n];
    f(0, 1, 0, c);

    for (int i = 0; i < n; i++)
        cout << b[i].X << " " << b[i].Y << "\n";
    return 0;
}
