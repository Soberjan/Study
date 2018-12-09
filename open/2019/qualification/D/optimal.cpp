#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

struct MyBitset{
    int k; unsigned long long *p;
    void init(int n){k=n/64; p=new unsigned long long[k];}
    void reset(){memset(p,0,8*(k+1));}
    void set(int num){int z = num/64; p[z]|=(1<<num%64);}
    void print(int x, int y){
        cout << k << "\n";
        for(int i=0; i<=k; i++)
            cout << p[i] << " ";
        cout << "\n";
    }
    int FindFirstZero(){
        int i, j;
        for(i=0; p[i] == ULLONG_MAX; i++);
        for(j=0; (p[i]&(1<<j))>0; j++);
        return i*64 + j;
    }
    void freemem(){delete[] p;}
};

int n, q, *a;
MyBitset mb;

int optimal(int x, int y){
    mb.reset();
    for (int i=x; i <= y; i++)
        mb.set(a[i]);
//    mb.print(x, y);
    return(mb.FindFirstZero());
}

int main()
{
    //freopen("tests/00", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    a = new int [n];
    for (int i=0; i<n; i++)
        cin >> a[i];
    mb.init(n);

    for (int i=0; i<q; i++){
        char c; int x, y;
        cin >> c >> x >> y;
        if (c=='?')
            cout << optimal(--x, --y) << "\n";
        else
            a[x-1]=y;
    }

    delete[] a;
    mb.freemem();
    return 0;
}
