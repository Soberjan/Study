#include <iostream>
#include <map>
using namespace std;

int n, a[100001];

int optimal(){
    map<int, int> partic;
    for (int i = 0; i < n; i++)
        partic[a[i]] += 1;

    int s = 0;
    for(map<int,int>::iterator it=partic.begin(); it!=partic.end(); ++it){
        int x = it->first;
        int y = it->second;
        s += y/x*x;
        //cout << x << " " << y << " " << s << "\n";
    }

    return s;
}

int main()
{
    //freopen("tests/02", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << optimal();
    return 0;
}
