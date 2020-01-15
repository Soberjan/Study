#include <iostream>
using namespace std;

string s;
int n, k, *a;

int main(){
//    freopen("tests/03", "r", stdin);
    cin >> s;
    if (s == "forward"){
        cin >> n >> k;
        a = new int[k];
        for (int i = 0; i < k; i++)
            cin >> a[i];

        if (k == 1)
            cout << "second " << 1;
        else{
            cout << "first ";
            for (int i = 0; i < k - 1; i++)
                cout << a[i] << " ";
        }
    }
    if (s == "reverse"){
        cin >> n >> k >> s;
        a = new int[k-1];
        for (int i = 0; i < k-1; i++)
            cin >> a[i];

        if (k == 1)
            cout << 1;
        else{
            for (int i = 0; i < k-1; i++)
                cout << a[i] << " ";
            cout << a[k-2] + 1 << " ";
        }
    }
    return 0;
}
