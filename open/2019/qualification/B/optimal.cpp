#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    //freopen("tests\\00", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, n;
    char c, d, buffer [20];
    cin >> n >> c;
    for (i = 1; i < n; i++){
        cin >> d;
        if (d != c)
            break;
    }
    sprintf(buffer, "Yes\n%d %d %d", 1, i + 1, 1);
    cout << (i < n ? buffer : "No");
    return 0;
}
