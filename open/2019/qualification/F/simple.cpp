#include <iostream>
#include <stdio.h>
using namespace std;

int n, *a = new int[1000], *b = new int[1000];
int c[1000][1000];

bool compare(int a[21], int b[21]){
    int i;
    for (i = 0; i < n; i++)
        if (a[i]!=b[i])
            break;
    if (i == n) return 1;
    else return 0;
}

void print(int c[21]){
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << "\n";
}

bool simple(){
    for (int i = 0; i < n; i++)
        c[0][i] = i + 1; 
//    print(c[0]);
    for (int i = 1; i < 100; i++){
        for (int j = 0; j < n; j++)
            c[i][a[j]-1]=c[i-1][j];
//        print(c[i]);
        if (compare(c[i], b))
            return 1;
        for (int j = 0; j < i; j++)
            if (compare(c[i], c[j]))
                return 0;
    }
    return 0;
}

int main()
{
//    freopen("tests/00", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << (simple() ? "Yes" : "No");
    return 0;
}
