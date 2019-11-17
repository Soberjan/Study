#include <iostream>
using namespace std;
#define X first
#define Y second
#define ll long long
#define f(i, j) ((i) * (n+1)) + j

struct quartet{ pair<ll, int> a[4]; };;

int n, k;
pair<int, int> *p, *ans;
quartet *b;
void print(){
    for (int i = 0; i < k + 1; i++){
        for (int j = 0; j < n + 1; j++)
            printf("%3d%3d%3d%3d|", (int)b[f(i, j)].a[0].X, (int)b[f(i, j)].a[1].X, (int)b[f(i, j)].a[2].X, (int)b[f(i, j)].a[3].X);
        printf("\n");
    }
    printf("\n");
}

int main(){
 //   freopen("tests/01", "r", stdin);
    cin >> n >> k;
    p = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].X >> p[i].Y;

    b = new quartet[(k+1) * (n+1)];
    for (int i = 0; i < (k+1) * (n+1); i++)
        b[i].a[0] = b[i].a[1] = b[i].a[2] = b[i].a[3] = make_pair(0, 0);
    for (int i = 1; i <= k; i++){
        ll x = p[i-1].X + p[i-1].Y;
        b[f(i, i)].a[3] = make_pair(x + b[f(i - 1, i)].a[0].X, 0);
        for (int j = i + 1; j <= n; j++){
            for (int q = 0; q < 4; q++)
                b[f(i, j)].a[0] = max(b[f(i, j)].a[0], make_pair(b[f(i, j-1)].a[q].X, q));

            x = p[j-1].Y + p[j-2].Y;
            b[f(i, j)].a[1] = max(make_pair(x + b[f(i-1, j-1)].a[0].X, 0), make_pair(x + b[f(i-1, j-1)].a[2].X, 1));

            x = p[j-1].X + p[j-2].X;
            b[f(i, j)].a[2] = max(make_pair(x + b[f(i-1, j-1)].a[0].X, 0), make_pair(x + b[f(i-1, j-1)].a[1].X, 1));

            x = p[j-1].X + p[j-1].Y;
            int y = b[f(i-1, j)].a[0].X;
            b[f(i, j)].a[3] = make_pair(x + y, 0);
        }
    }
    //print();

    ans = new pair<int, int>[n];
    int idx = 0;
    for (int i = 1; i < 4; i++){
        int x = b[(n+1) * (k+1) - 1].a[idx].X;
        int y = b[(n+1) * (k+1) - 1].a[i].X;
        if (x < y)
            idx = i;
    }
    for (int i = k, j = n; i > 0; )
        if (idx == 0){
            idx = b[f(i, j)].a[idx].Y;
            j--;
        }
        else if (idx == 1){
            ans[j-1].Y = ans[j-2].Y = i;
            idx = (b[f(i, j)].a[idx].Y == 0) ? 0 : 2;
            i--;
            j--;
        }
        else if (idx == 2){
            ans[j-1].X = ans[j-2].X = i;
            idx = (b[f(i, j)].a[idx].Y == 0) ? 0 : 1;
            i--;
            j--;
        }
        else if (idx == 3){
            ans[j-1].X = ans[j-1].Y = i;
            idx = 0;
            i--;
        }

    for (int i = 0; i < n; i++)
        cout << ans[i].X << " " << ans[i].Y << "\n";


    return 0;
}
