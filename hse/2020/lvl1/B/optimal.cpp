#include <iostream>
using namespace std;
#define X first
#define Y second
#define ll long long
#define f(i, j) (i * n) + j

struct quartet{ int a[4] = {0, 0, 0, 0}; };

int n, k;
pair<int, int> *p;
quartet *b;
void print(){
    for (int i = 0; i < k + 1; i++){
        for (int j = 0; j < n + 1; j++)
            printf("%3d:%3d:%3d:%3d |", b[f(i, j)].a[0], b[f(i, j)].a[1], b[f(i, j)].a[2], b[f(i, j)].a[3]);
        printf("\n");
    }
    printf("\n");
}

int main(){
    freopen("tests/00", "r", stdin);
    cin >> n >> k;
    p = new pair<int, int>[n+1];
    for (int i = 1; i <= n; i++)
        cin >> p[i].X >> p[i].Y;

    b = new quartet[(k+1) * (n+1)];
    print();
    for (int i = 1; i <= k; i++)
        for (int j = i; j < n; j++){
            for (int q = 0; q < 4; q++)
                b[f(i, j)].a[0] = max(b[f(i, j)].a[0], b[f(i, j-1)].a[q]);

            int x = p[j+1].Y + p[j].Y;
            b[f(i, j)].a[1] = max(b[f(i, j)].a[1], x + b[f(i-1, j)].a[2]);
            b[f(i, j)].a[1] = max(b[f(i, j)].a[1], x + b[f(i-1, j-1)].a[2]);
            b[f(i, j)].a[1] = max(b[f(i, j)].a[1], x + b[f(i-1, j-1)].a[0]);
            //print();
            x = p[j+1].X + p[j].X;
            b[f(i, j)].a[2] = max(b[f(i, j)].a[2], x + b[f(i-1, j)].a[1]);
            b[f(i, j)].a[2] = max(b[f(i, j)].a[2], x + b[f(i-1, j-1)].a[1]);
            b[f(i, j)].a[2] = max(b[f(i, j)].a[2], x + b[f(i-1, j-1)].a[0]);

            b[f(i, j)].a[3] = p[j+1].X + p[j+1].Y + b[f(i-1, j)].a[0];
        }
    print();


    return 0;
}
