#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define ll long long

int b, k;
string n;

int pow_(int num, int exp){
    if (exp == 0)
        return 1;
    if (exp > 0) {
        int result = 1;
        for (int i = 0; i < exp; ++i) {
            result *= num;
        }
        return result;
    }
    return -1;
}
unsigned int char2int_(char chr){
    if (chr >= '0' && chr <= '9')
        return chr - '0';
    else if (chr >= 'a' && chr <= 'f')
        return chr - 'a' + 10;
    return -1;
}
int hex2dec_(const char *hex, int size){
    int dec = 0;
    for (int j = 0, i = size - 1; j < size; ++j, --i) {
        dec += char2int_(hex[j]) * pow_(16, i);
    }
    return dec;
}

vector<ll> v;
void primeFactors(int n){
    while (n % 2 == 0)  {
        v.push_back(2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            v.push_back(i);
            n = n/i;
        }
    }

    if (n > 2)
        v.push_back(n);
}

string f(ll n){
    string s;
    map<int, char> m = { {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},  {10, 'a'}, {11, 'b'}, {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}};
    while (n > 0){
        int q = n % 16;
        if (m.find(q) != m.end())
            s += m[q];
        else
            s += q;
        n = n / 16;
    }
    return s;
}

int main(){
  //  freopen("tests/01", "r", stdin);
    cin >> b >> k >> n;

    ll num = hex2dec_(n.c_str(), n.length());
    primeFactors(num);

    for (ll x : v){
        string s = f(x);
        int n = (int)s.size();
        for (int i = n - 1; i >= 0; i--)
            cout << s[i];
        cout << "\n";
    }


    return 0;
}
