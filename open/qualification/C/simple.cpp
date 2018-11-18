#include <iostream>
#include <algorithm>
using namespace std;
int n, q, a[500000];
void simple(){
    int sum;
    for (int i = 0; i < n; i++)
        sum += a[i] % k;
    int sum2 = sum;
    int money = q;
    int mod = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > k)
            mod = a[i] % k;
        if (a[i] < k)
            mod = q - k % a[i];
        sum2 += 1;              //simple получаетс€ слишком сложным. Ќужно рассмотреть все вожможные варианты распределни€ бурлей и выбрать тот, который даст максимальное значение sum
    }
}

int main()
{
    //freopen("tests\\05", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    simple();
    return 0;
}
