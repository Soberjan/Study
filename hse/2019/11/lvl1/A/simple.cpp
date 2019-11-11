#include <iostream>
#include <string>
using namespace std;

string s1, s2, s3;

string findmax(string s1, string s2, string s3){
    string s = "";
    for (int i = 0; i < (int)s1.size(); i++)
        for (int j = i; j < (int)s1.size(); j++){
            string t = s1.substr(i, j - i + 1);
            if (((int)s2.find(t) != -1) && ((int)s3.find(t) != -1) && (t.size() > s.size()))
                s = t;
        }
    return s;
}

int main(){
//    freopen("tests/00", "r", stdin);
    cin >> s1 >> s2 >> s3;
    string s;
    s = max(findmax(s1, s2, s3), s);
    cout << s;
    return 0;
}
