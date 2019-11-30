#include <iostream>
#include <string>
using namespace std;

int n;
int main(){
    freopen("tests/01", "r", stdin);
    cin >> n;

    int m = 0;
    for (int i = 1000; i < 10000; i++){
        int q = i;
        int a = q % 10;
        q /= 10;
        int b = q % 10;
        q /= 10;
        int c = q % 10;
        q /= 10;
        int d = q % 10;
        q /= 10;
        int e = a + b;
        int f = c + d;
        string s =  to_string(e) + to_string(f);
        if (stoi(s) == n){
            m = i;
            break;
        }
    }

    cout << m;
    return 0;
}
