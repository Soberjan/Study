#include <iostream>
#include <algorithm>

using namespace std;
const int NLIM = 100, HLIM = 100;
int n, k, a[NLIM][HLIM], b[NLIM], s;

void print(){
    for (int i = 0; i < NLIM; i++){
        for (int j = 0; j < HLIM; j++)
            cout << a[j];
        cout << "\n";
        }
    }

void simple(){
    print();
    }


int main(){
    //freopen("tests\\00", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> b[i];

    simple();

    cout << s;

    return 0;
}
