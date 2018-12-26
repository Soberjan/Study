#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string a[100];
int n;

int main()
{
    //freopen("tests/00", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
//    for (int i = 0; i < n; i++)
//        cout << str[i] << " ";
    int dot = 0, sum = 0, name_len = 0, ext_len = 0;
    for (int i = 0; i < n; i++, dot = 0, name_len = 0, ext_len = 0){
        string str = a[i];
        cout << str << "\n";
        for (unsigned int j = 0; j < str.length(); j++){
            if ((str[j] != '.') && (dot == 0))
                name_len++;
            else if (str[j] == '.')
                dot += 1;
            else if (dot == 1)
                ext_len++;
        }
        if ((name_len > 0) && (name_len <= 8) && (dot == 1) && (ext_len > 0) && (ext_len <= 3))
            sum += 1;
    }

    cout << sum;
    return 0;
}
