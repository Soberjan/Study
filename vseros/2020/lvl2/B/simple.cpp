#include <iostream>
using namespace std;
#define ll long long
int n, k;

string smax, ans; ll i = 0, kmax;
void f(string &s, ll h, ll l){
    if (h >= l)
        return ;
    for (ll j = k; j <= kmax; j+=k, i++){
        if (i == n){
            ans = s;
            break;
        }
        if (s == smax)
            break;
        s[h] = j;
        f(s, h+1, l);
        s[h] = 0;
    }
}

int main(){
    cin >> n >> k;

    for (kmax = k; kmax < 10; kmax += k);
    kmax -= k;
    string s;
    for (ll l = 1; i < n; l++){
        smax = "";
        s = "";
        for (ll j = 0; j < l; j++)
            smax[i] = kmax;
        for (ll j = 0; j < l; j++)
            s[j] = 0;
        cout << smax << " " << s;
        for (ll j = k; j <= kmax; j+=k, i++){
            if (i == n){
                ans = s;
                break;
            }
            if (s == smax)
                break;
            s[0] = j;
            f(s, 1, l);
        }
    }
    cout << ans;
    return 0;
}
