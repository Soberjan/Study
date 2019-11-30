#include <iostream>
using namespace std;

int n;

int main(){
    //freopen("tests/00", "r", stdin);
    cin >> n;

    cout << n / 48 << " ";
    n %= 48;
    cout << n / 16 << " ";
    n %= 16;
    cout << n / 4 << " ";
    n %= 4;
    cout << n << " ";

    return 0;
}
