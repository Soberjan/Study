#include <iostream>
using namespace std;

string s;

int f(string s){
//    cout << s << endl;
    int n = s.size(), m = n;
    bool u = 0;
    for (int i = 1; i <= n/2; i++){
        string s1 = s.substr(0, i);
        string s2 = s.substr(n-i, i);
        if (s1 == s2){
            u = 1;
            s1 = s.substr(i, n - i);
            s2 = s.substr(0, n - i);
            int m1 = f(s1);
            int m2 = f(s2);
            m = min(m, min (m1, m2));

        }
    }
    if (!u)
        return n;
    return m;
}

int main(){
   // freopen("tests/04", "r", stdin);
    cin >> s;
    cout << f(s);

    return 0;
}
