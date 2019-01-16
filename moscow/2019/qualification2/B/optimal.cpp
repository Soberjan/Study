#include <iostream>
#include <stdio.h>
using namespace std;

string line;

int main()
{
    freopen("tests/00", "r", stdin);
    while (getline(cin, line))
    {
        cout << line << endl;
    }
    return 0;
}
