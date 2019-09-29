#include <iostream>
using namespace std;

unsigned long long n, m; //не забыть задать вопрос

int main()
{
//    freopen("tests/03", "r", stdin);
    cin >> n >> m;

    unsigned long long s, s1, s2;
    s1 = (n * m + m) * n / 2;
    s2 = (n + 1) * n / 2;
    s = (s1 + s2) * m / 2;

    cout << s;
    return 0;
}
