#include <iostream>
#include <string>
using namespace std;

string str;

int main()
{
    freopen("tests/04", "r", stdin);
    cin >> str;
    int sum = 0, n = (int)str.size();
    bool cor = 1;

    for (int i = 0; i < n; i += 3){
        int  tmp = stoi(str.substr(i, 3));
        if ((( (tmp >= 'a') && (tmp <= 'z') ) || ( (tmp >= 'A') && (tmp <= 'Z') )) == 0)
            cor = 0;
    }
    sum += cor;

    int *a = new int[n / 3];
    for (int d = 0; d < 10; d++){
        for (int i = 0; i < n / 3; i++){
            string tmp = str.substr(i, 3);
            if (tmp.find(string(d))){

            }
            else

        }
        int tsm = 1;
        for (int i = 0; i < n / 3; i++)
            tsm *= a[i];
        sum += tsm;
    }

    cout << sum;
    return 0;
}
