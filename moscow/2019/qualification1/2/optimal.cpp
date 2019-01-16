#include <iostream>
#include <stdio.h>
#include<string>
using namespace std;

string s;

int main()
{
    freopen("tests/03", "r", stdin);
    cin >> s;

    int sum = 0;
    for (unsigned int i = 0, raw = 0; i < s.length(); raw == 0 ? i++ : i+=2, raw =0){
        if (s[i]=='I'){
            if (s[i+1]=='V'){
                sum += 4;
                raw = 1;
                continue;
            }
            else if (s[i+1]=='X'){
                sum += 9;
                raw = 1;
                continue;
            }
            else sum += 1;
        }
        if (s[i]=='X'){
            if (s[i+1]=='L'){
                sum += 40;
                raw = 1;
                continue;
            }
            else if (s[i+1]=='C'){
                sum += 90;
                raw = 1;
                continue;
            }
            else sum += 10;
        }
        if (s[i]=='C'){
            if (s[i+1]=='D'){
                sum += 400;
                raw = 1;
                continue;
            }
            else if (s[i+1]=='M'){
                sum += 900;
                raw = 1;
                continue;
            }
            else sum += 100;
        }
        if(s[i]=='V')
            sum+= 5;
        if (s[i]=='L')
            sum += 50;
        if (s[i]=='D')
            sum += 500;
        if (s[i]=='M')
            sum += 1000;
    }

    cout << sum;

    return 0;
}
