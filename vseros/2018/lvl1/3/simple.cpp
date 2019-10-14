#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int m;

int main()
{
    //freopen("tests/02", "r", stdin);
    cin >> m;
    list<int> p(1, 1);
    int q = 2, n = m;
    while (n != 1)
        if (n % q == 0) {
            p.push_back(q);
            n /= q;
        }
        else if (q == n / 2){
            p.push_back(n);
            n = 1;
        }
        else
            q++;
    p.push_back(1);

    int s = 1, k = 0, prev = 1;
    for (int i : p){
        if (i == prev)
            k++;
        else{
            s = k % 2 == 0 ? s * floor(pow(prev, k)) : s * floor(pow(prev, k - 1));
            prev = i;
            k = 1;
        }
    }

    cout << s;
    return 0;
}
