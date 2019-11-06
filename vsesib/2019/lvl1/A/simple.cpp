#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int VLIM = 1e9;

int main()
{
    //freopen("tests/05", "r", stdin);

    vector<int> v{2, 3};
    for (int i = 5; i < VLIM; i+=2){
        int d = 0;
        for (int j = 0; (j < (int)v.size()) && (v[j] <= sqrt(i)); j++)
            if (!(d = i % v[j]))
                break;
        if (d)
            v.push_back(i);
    }
    for (int i = 0; i < 100; i++)
        cout << v[i] << " ";
    cout << "\n";
    cout << v.size();
    return 0;
}
