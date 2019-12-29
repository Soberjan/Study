#include <iostream>
using namespace std;

string s;
void replace(int i, int j){
    char t = s[i];
    s[i] = s[j], s[j] = t;
}

int main(){
//    freopen("tests/01", "r", stdin);
    cin >> s;
    int n = (int)s.size();
    if (n == 1){
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < n - n % 2; i+=2)
        replace(i, i+1);
    if (n % 2)
        replace(0, n-1);
    cout << s;
    return 0;
}
