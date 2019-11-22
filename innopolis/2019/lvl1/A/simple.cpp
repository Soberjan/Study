#include <iostream>
#include <map>
using namespace std;

string s1, s2;

int main(){
//    freopen("tests/01", "r", stdin);
    cin >> s1 >> s2;

    map<char, int> m;
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;
    m['e'] = 5;
    m['f'] = 6;
    m['g'] = 7;
    m['h'] = 8;
    cout << ( m[s1[0]] > m[s2[0]] ? m[s1[0]] - m[s2[0]] : m[s2[0]] - m[s1[0]] ) << " " << ( s1[1] > s2[1] ? (int)s1[1] - (int)s2[1] : (int)s2[1] - (int)s1[1] );
    return 0;
}
