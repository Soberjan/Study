#include <iostream>
#include <bitset>
using namespace std;

const int LIM = 100000;
int n, *a;

bitset<LIM> f(int n){
    bitset<LIM> bs;
    bs[2] = !(n % 2);
    while (n % 2 == 0)
        n /= 2;
    for (int i = 3; i < n / 2; i+=2){
        bs[i] = n % i;
        while ( (n % i) == 0)
            n /= i;
    }
    if (n > 2)
        bs[n] = n;
    return bs;
}

int main(){
//    freopen("tests/00", "r", stdin);
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bitset<LIM> bs;
    bs.set(); bs[0] = bs[1] = 0;
    for (int i = 0; i < n; i++)
        bs = bs & f(abs(a[i]));

    if (bs.count() == 0){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    int m = a[0];
    for (int i = 0; i < n; i++)
        m = min(m, abs(a[i]));
    cout << m << " ";
    cout << bs._Find_first();
    return 0;
}
