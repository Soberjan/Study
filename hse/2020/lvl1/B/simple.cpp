#include <iostream>
#include <cstring>
using namespace std;
#define X first
#define Y second

int n, k, smax;
pair<int, int> *a, *b, *c;

void print(pair<int, int> *c){
    for (int i = 0; i < n; i++)
        cout << c[i].X << " " << c[i].Y << "\n";
}

void f(int p, int q, int s){
    for (int i = p; (i < n) && (q <= k); i++){
        if ((c[i].X == 0) && (c[i].Y == 0)){
            c[i].X = c[i].Y = q;
            s += (a[i].X + a[i].Y);
            if (s > smax)
                memcpy(b, c, sizeof(pair<int, int>) * n), smax = s;
//            print(c);
//            cout << s << " " << smax << "\n\n";
            f(i + 1, q + 1, s);
            c[i].X = c[i].Y = 0;
            s -= (a[i].X + a[i].Y);
        }
        if ((i + 1 < n) && (c[i].Y == 0)){
            c[i].Y = c[i+1].Y = q;
            s += (a[i].Y + a[i+1].Y);
            if (s > smax)
                memcpy(b, c, sizeof(pair<int, int>) * n), smax = s;
//            print(c);
//            cout << s << " " << smax << "\n\n";
            f(i + 1, q + 1, s);
            c[i].Y = c[i+1].Y = 0;
            s -= (a[i].Y + a[i+1].Y);
        }
        if ((i + 1 < n) && (c[i].X == 0)){
            c[i].X = c[i+1].X = q;
            s += (a[i].X + a[i+1].X);
            if (s > smax)
                memcpy(b, c, sizeof(pair<int, int>) * n), smax = s;
//            print(c);
//            cout << s << " " << smax << "\n\n";
            f(i + 1, q + 1, s);
            c[i].X = c[i+1].X = 0;
            s -= (a[i].X + a[i+1].X);
        }
    }
}

int main(){
//    freopen("tests/02", "r", stdin);
    cin >> n >> k;
    a = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;

    b = new pair<int, int>[n];
    c = new pair<int, int>[n];
    f(0, 1, 0);

    for (int i = 0; i < n; i++)
        cout << b[i].X << " " << b[i].Y << "\n";
    return 0;
}
