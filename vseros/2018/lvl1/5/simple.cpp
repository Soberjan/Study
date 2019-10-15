#include <iostream>
using namespace std;

string s;

int main()
{
    //8freopen("tests/00", "r", stdin);
    cin >> s;
    int d[4] = {0};
    for (int i = 0, p = 0; i < (int)s.size(); i++)
        if (s[i] == 'N'){
            string s1(s.begin() + p, s.begin() + i);
            d[0] += stoi(s1);
            p = i + 1;
        }
        else if (s[i] == 'S'){
            string s1(s.begin() + p, s.begin() + i);
            d[1] += stoi(s1);
            p = i + 1;
        }
        else if (s[i] == 'E'){
            string s1(s.begin() + p, s.begin() + i);
            d[2] += stoi(s1);
            p = i + 1;
        }
        else if (s[i] == 'W'){
            string s1(s.begin() + p, s.begin() + i);
            d[3] += stoi(s1);
            p = i + 1;
        }
    if (d[0] != d[1])
        cout << ( d[0] - d[1] > 0 ? d[0] - d[1] : d[1] - d[0] ) << ( d[0] - d[1] > 0 ? 'N' : 'S' );
    if (d[2] != d[3])
        cout << ( d[2] - d[3] > 0 ? d[2] - d[3] : d[3] - d[2] ) << ( d[2] - d[3] > 0 ? 'E' : 'W' );
    return 0;
}
