#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int n, p, x, *a;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> n >> p >> x;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans;
    for (ll i = 0; ; i++){
        ll q = x + i * p;
        for (int j = 0; j < n; j++)
            if (q % a[j] == 0){
                q = q / a[j];
                ans.push_back(a[j]);
            }
        if (q == 1)
            break;
        ans.clear();
    }
    for (int x : ans)
        cout << x << " ";
    return 0;
}
