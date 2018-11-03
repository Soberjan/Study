#include <iostream>
using namespace std;

void fix_time(int& h, int& minutes, int& days) {
    h += minutes / 60;
    minutes = minutes % 60;
    days += h / 24;
    h = h % 24;
}

int main()
{
    int hd, md, hf, mf, d, a;
    cin >> hd >> md >> hf >> mf >> d >> a;

    int h = hd, m = md, days = 0;
    fix_time(h += 24 - d, m, --days);
    fix_time(h += hf, m += mf, days);
    fix_time(h += 24 + a, m, --days);

    cout << h << " " << m << " " << days;
    return 0;
}
