#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second

int n, k, *a;

vector<pair<int, int>> ans;
bool f(int i, int j){
//    cout << i << " " << j << endl;
    if ((i == n*2) && (j != 0))
        return 0;
    if (((j < 0) || (j == 0)) && (i < n*2))
        return 0;
    if ((i == n*2) && (j == 0)){
        ans.push_back({0,i});
        return 1;
    }

    bool yes = 0;
    for (int q = i+2; q <= n*2; q+=2){
        yes = yes || f(q, j - (a[q-1] - a[i]));
        if (yes){
            ans.back().X = i+1;
            ans.push_back({0, i});
            break;
        }
    }
    return yes;
}

int main(){
    freopen("tests/00", "r", stdin);
    cin >> n >> k;
    a = new int[n*2];
    for (int i = 0; i < n*2; i++)
        cin >> a[i];

    if (f(0, k)){
        cout << "Yes" << endl;
        ans.pop_back();
        for (pair<int, int> x : ans)
            for (int i = x.X+1; i < x.Y; i+=2)
                ans.push_back({i, i+1});
        for (int i = 0; i < (int)ans.size(); i++)
            cout << ans[i].X << " " << ans[i].Y << endl;
    }
    else
        cout << "No";
    return 0;
}
