#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bitset>
using namespace std;

int n, *a = new int [1000000], *b = new int [1000000];

void print(bitset<100> a){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int optimal(){
    int ji;
    for (ji = 0; ji < n; ji++)
        if (a[ji]!=b[ji])
            break;
    if (ji == n) return 0;

    bitset<1000000> u;// увеличить размер
    u.set();
    for (int i = n; i != 0;){ // как оформить? i=n или i=0?
        bitset<1000000> sh; sh[n] = 1;  // создаем "графы"
        for (int j = u._Find_first(); u[j]==1; u[j]=0, sh[j]=1, i--, j=a[j]-1);
//        print(u);
//        print(sh);

        for (int j = sh._Find_first(); j < n; j = sh._Find_next(j)){ //проверяем, если в массиве b нам необходимо анализировать значение, выходящее за пределы нашего "графа"
            bool ch = 0;
            for (int q = sh._Find_first(); q < n; q = sh._Find_next(q))
                if (b[q]==j + 1)
                    ch = 1;
            if (ch==0)
                return 0;
        }

        int s1 = 0, s2 = 0, j = sh._Find_first();
        for (int q = b[j] - 1; q != j;){
                s1++;
                q = a[q] - 1;
            }
        for (j = sh._Find_next(j); j < n; s2 = 0, j = sh._Find_next(j)){
            for (int q = b[j] - 1; q != j;){
                s2++;
                q = a[q] - 1;
            }
            if (s1 != s2)
                return 0;
        }
    }
    return 1;
}

int main()
{
    //freopen("tests/08", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << (optimal() == 1 ? "Yes" : "No");

    return 0;
}
