#include <iostream>
using namespace std;

int n, m; double d;
double *b = new double[n];
char** a = new char*[m];

void print(){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << "\n";
    }
}

void simple(){
    for (int i = 0; i < m; i++){
        int dt = 0, idx = 0;
        for (int j = 0; j < n;  j++)
            if (a[i][j] == '+'){
                dt++;
                idx = j;
            }
        if (dt == 1){
            b[idx]+=1;
            d++;
            //cout << b[idx] << " ";
        }
    }
}

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        a[i] = new char[n];
    for (int i = 0; i < n; i++){
        b[i] = 0;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    simple();

    for (int i = 0; i < n; i++)
        if (b[i] / d >= 0.07)
            cout << i + 1 << " ";

   // print();
    return 0;
}
