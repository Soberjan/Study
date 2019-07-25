#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    //freopen("tests/02", "r", stdin);
    string s;
    cin >> s;
    bitset<10> bs(string("1111111111"));
    for (int i = 0; i < int(s.size()); i+=3){
        char ts[3];
        s.copy(ts, 3, i);
        int code = atoi(ts);
        if (code > 122){
            bitset<10> tbs = {000000000};
            if ( ( (code / 10 >= 65) && (code / 10 <= 90) ) || (code / 10 >= 97))
                tbs[code % 10] = 1;
            if ( ( (code % 100 >= 65) && (code % 100 <= 90) ) || (code % 100 >= 97))
                tbs[code / 100] = 1;
            if ( ( (code / 100 * 10 + code % 10 >= 65) && (code / 100 * 10 + code % 10 <= 90) ) || (code / 100 * 10 + code % 10 >= 97))
                tbs[code / 10 % 10] = 1;
            bs &= tbs;
        }
    }
    cout << bs.count();
    return 0;
}
