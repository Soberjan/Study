#include <iostream>
using namespace std;

unsigned long long n, k;

int main()
{
    //freopen("tests/02", "r", stdin);
    cin >> n >> k;

    unsigned long long m = 1; int l = 1;
    while (m < k){
        m = m * 2 + 1;
        l++;
    }
    m = (m + 1) / 2 - 1;

    unsigned long long p1 = n, p2 = 0, q1 = 1, q2 = 0;
    for (int i = 1; i < l; i++){
        if (p1 % 2 == 0)
            if (p2 == 0){
                q2 = q1;
                p1 /= 2;
                p2 = p1 - 1;
            }
            else{
                q2 = q2 * 2 + q1;
                p1 /= 2;
                p2 = p1 - 1;
            }
        else
            if (p2 == 0){
                q1 *= 2;
                p1 /= 2;
            }
            else{
                q1 = q1 * 2 + q2;
                p1 = p2 / 2;
                p2 = p1 - 1;
            }
    }

    if (k - m <= q1)
        if (p1 % 2 == 0)
            cout << p1 / 2 - 1 << "\n" << p1 / 2;
        else
            cout << p1 / 2 << "\n" << p1 / 2;
    else
        if (p2 % 2 == 0)
            cout << p2 / 2 - 1 << "\n" << p2 / 2;
        else
            cout << p2 / 2 << "\n" << p2 / 2;

    return 0;
}
