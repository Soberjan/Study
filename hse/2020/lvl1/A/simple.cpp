#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define X first
#define Y second

int n;

int main(){
    //freopen("tests/00", "r", stdin);
    map<string, ll> m;
    vector<pair<string, int>> v;
    cin >> n;
    int amount;
    string command, type;
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == "add"){
            cin >> amount >> type;
            m[type] += amount;
            v.push_back({type, amount});
        }
        if (command == "get"){
            cin >> type;
            cout << m[type] << "\n";
        }
        if (command == "delete"){
            cin >> amount;
            while(amount > 0){
                pair<string, int> vagon = v.back();
                if (amount >= vagon.Y){
                    amount -= vagon.Y;
                    m[vagon.X] -= vagon.Y;
                    v.pop_back();
                }
                else{
                    v.back().Y -= amount;
                    m[vagon.X] -= amount;
                    amount = 0;
                }
            }
        }
    }

    return 0;
}
