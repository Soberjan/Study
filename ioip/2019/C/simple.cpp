#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
//    freopen("tests/04", "r", stdin);
    string s;
    cin >> s;
    bitset<10> bs(string("1111111111"));
    for (int i = 0; i < int(s.size()); i+=3){
        char ts[3];
        s.copy(ts, 3, i);
        int code = atoi(ts);
        if (code > 'z'){
            bitset<10> tbs = {000000000};
            if ( ( (code / 10 >= 'A') && (code / 10 <= 'Z') ) || (code / 10 >= 'a'))
                tbs[code % 10] = 1;
            if ( ( (code % 100 >= 'A') && (code % 100 <= 'Z') ) || (code % 100 >= 'a'))
                tbs[code / 100] = 1;
            if ( ( (code / 100 * 10 + code % 10 >= 'A') && (code / 100 * 10 + code % 10 <= 'Z') ) || (code / 100 * 10 + code % 10 >= 'a'))
                tbs[code / 10 % 10] = 1;
            bs &= tbs;
        }
    }
    if ((int)bs.count() == 10)
        cout << 1;
    else
        cout << bs.count();
    return 0;
}
