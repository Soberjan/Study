#include <iostream>
#include <set>
using namespace std;
#define ll long long

int n;
ll k, t;

struct trio{
    ll a, b, c;
};

trio operator+(trio num, int d){
    num.a = num.a + (num.c + d) / num.b;
    num.c = (num.c + d) % num.b;
    return num;
}

int main(){
    //freopen("tests/01", "r", stdin);
    cin >> n >> k >> t;
    multiset<int> h;
    for (int i = 0; i < n; i++){
        int a, b; char c;
        cin >> a >> c >> b;
        h.insert(a * b);
    }

    ll mn = min(k, t), mx = max(k, t);
    trio num = {0, mx, 0};
    int q = 0;
    for (auto x : h){
        num = num + x;
        if ((num.a < mn) || ( (num.a == mn) && (num.c == 0) ) )
            q++;
        else
            break;
    }
    cout << q;
    return 0;
}
