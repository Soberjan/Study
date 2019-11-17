#include <iostream>
using namespace std;
#define X first
#define Y second
#define ll long long
#define f(i, j) (i * (n+1)) + j

struct quartet{ pair<ll, int> a[4]; };;

int n, k;
pair<int, int> *p;
quartet *b;
void print(){
    for (int i = 0; i < k + 1; i++){
        for (int j = 0; j < n + 1; j++)
            printf("%3d:%3d:%3d:%3d |", (int)b[f(i, j)].a[0].X, (int)b[f(i, j)].a[1].X, (int)b[f(i, j)].a[2].X, (int)b[f(i, j)].a[3].X);
        printf("\n");
    }
    printf("\n");
}

int main(){
    freopen("tests/00", "r", stdin);
    cin >> n >> k;
    p = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].X >> p[i].Y;

    b = new quartet[(k+1) * (n+1)];
    for (int i = 2; i <= k; i++)
        for (int j = i + 1; j <= n; j++){
            for (int q = 0; q < 4; q++)
                b[f(i, j)].a[0] = max(b[f(i, j)].a[0], make_pair(b[f(i, j-1)].a[q].X, q));

//            int x = p[i-1].Y + p[i-2].Y;
//            b[f(i, j)].a[1] = max(make_pair(x + b[f(i-1, j-1)].a[2].X, 0), make_pair(x + b[f(i-1, j-1)].a[0].X, 1));
//
//            x = p[i-1].X + p[i-2].X;
//            b[f(i, j)].a[2] = max(make_pair(x + b[f(i-1, j-1)].a[1].X, 0), make_pair(x + b[f(i-1, j-1)].a[0].X, 1));

            int x = p[i-1].X + p[i-1].Y;
            b[f(i, j)].a[3] = make_pair(x + b[f(i-1, j)].a[0].X, 0);
        }

    print();

    return 0;
}
