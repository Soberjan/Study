#include <iostream>
#include <algorithm>
#include <time.h>
#include <bitset>
using namespace std;

const int NLIM = 15;
const int VLIM = 20;
int n, a[100], b[100];
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

void print1(bitset<100> a){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}


bool simple(){
    for (int i = 0; i < n; i++)
        c[0][i] = i+1; // инкрементация? вспомнить.
    //print(c[0]);
    for (int i = 1; i < 100; i++){
        for (int j = 0; j < n; j++)
            c[i][a[j]-1]=c[i-1][j];
        //print(c[i]);
        if (compare(c[i], b) == 1)
            return 1;
        for (int j = 0; j < i; j++)
            if (compare(c[i], c[j]) == 1)
                return 0;
    }
    return 0;
}

int optimal(){
    bitset<1000000> u;// увеличить размер
    u.set();
    pair<int, int>* sum = new pair<int, int>[n];
    for (int i = n, q = 0; i != 0; q++){ // как оформить? i=n или i=0?
        bitset<1000000> sh; sh[n] = 1; int s = 0;  // создаем "графы"
        for (int j = u._Find_first(); u[j]==1; u[j]=0, sh[j]=1, i--, s++, j=a[j]-1);
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

        sum[q].first = s; sum[q].second = s1;
        for (int i = 0; i < q; i++){
            pair<int, int> mx, mn;
            mx = (sum[q].first > sum[i].first) ? sum[q] : sum[i];
            mn = (mx==sum[q]) ? sum[i] : sum[q];
            if ((mx.first == 1) || (mn.first == 1))
                continue;
            if ((mx.first % mn.first == 0) && (mx.second % mn.first != mn.second))
                return 0;
        }
    }
    return 1;
}

int d[100], e[100];
int main()
{
    srand(time(0));
    for (int i = 0; i < 10000; i++){
        n = rand() % 15 + 5;
        for (int j = 0; j < n; j++){
            int c = rand() % n + 1;
            while (d[c]!=0)
                c = rand() % n + 1;
            d[c] = 1;
            a[j] = c;
        }
        for (int j = 0; j < n; j++){
            int c = rand() % n + 1;
            while (e[c]==1)
                c = rand() % n + 1;
            e[c] = 1;
            b[j] = c;
        }
        if(simple() != optimal()){
            cout << "error!";
            cout << simple();
            cout << optimal();
        }
        for (int j = 0; j <= n; j++)
            d[j] = 0;
        for (int j = 0; j <= n; j++)
            e[j] = 0;
        //cout << i;
    }
    cout << "done!";
    return 0;
}
