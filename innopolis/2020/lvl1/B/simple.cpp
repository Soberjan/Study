#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define ll long long

int n;
string *s;

ll sum = 1e6, m;
char **t;
void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << t[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void f(int i){
    if (i == -1){
        ll s = 0;
        for (int j = 0; j < m; j++){
            map<char, int> mp;
            for (int q = 0; q < n; q++)
                mp[t[q][j]]++;
            int num = (*(mp.begin())).first == '0' ? n - (*(mp.begin())).second : n;
            int x = (*(--mp.end())).second;
            for (pair<char, int> q : mp)
                x = max(x, q.second);
            s += num - x;
            mp.clear();
        }
        //cout << s << "\n";
        sum = min(s, sum);
    }
    else{
        for (int j = 0; j < m; j++)
            if (j + (int)s[i].size() <= m){
                memcpy(t[i] + j, s[i].c_str(), sizeof(char) * (int)s[i].size());
                //print();
                f(i-1);
                fill(t[i]+ j, t[i] + n, '0');
            }
    }
}

bool compare(string &s1,string &s2){ return s1.size() < s2.size(); }

int main(){
   // freopen("tests/02", "r", stdin);
    cin >> n;
    s = new string[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s + n, compare);
    m = (int)s[n-1].size();
    t = new char*[n];
    for (int i = 0; i < n; i++){
        t[i] = new char[m];
        fill(t[i], t[i] + m, '0');
    }
    f(n-1);

    cout << sum;

    return 0;
}
