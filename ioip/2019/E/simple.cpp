#include <iostream>
using namespace std;

int n, *a, *b;

int s = 0;
void f(bool* u){
    for (int i = 0; i < n; i++){
        bool fits = 1;
        for (int j = 0; j < n - 1; j++)
            if ( ( b[j] == i ) && ( !u[a[j]] ) )
                fits = 0;
        if ( (fits) && (!u[i]) ){
            u[i] = 1;
            bool full = 1;
            for (int q = 0; q < n; q++)
                if (!u[q])
                    full = 0;
            if (full)
                s++;
            else
                f(u);
            u[i] = 0;
        }
    }
}

int main()
{
//    freopen("tests/03", "r", stdin);
    cin >> n;
    a = new int[n], b = new int[n];
    for (int i = 0; i < n - 1; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; a[i]--, b[i]--, i++);

    bool *u = new bool[n];
    for (int i = 0; i < n; i++)
        u[i] = 0;
    f(u);

    cout << s;
    return 0;
}
