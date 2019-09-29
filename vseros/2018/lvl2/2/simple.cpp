#include <iostream>
using namespace std;

string s;

int main()
{
   // freopen("tests/08", "r", stdin);
    cin >> s;
    int len = int(s.length()), sum = 0;
    for (int i = 0; i < len; i++){
        if (s[i] == 'V')
            sum += 5;
        else if (s[i] == 'L')
            sum += 50;
        else if (s[i] == 'D')
            sum += 500;
        else if (s[i] == 'M')
            sum += 1000;
        else if (s[i] == 'I'){
                if ((i <= len - 4) && (s[i+2] == 'C') && (s[i+3] == 'M')){
                    sum += 909; i += 3;
                }
                else if ((i <= len - 3) && (s[i+2] == 'C')){
                    sum += 91; i += 2;
                }
                else if ((i <= len - 2) && (s[i + 1] == 'X')){
                    sum += 9; i += 1;
                }
                else if ((i <= len - 2) && (s[i + 1] == 'V')){
                    sum += 4; i += 1;
                }
                else
                    sum += 1;
        }
        else if (s[i] == 'X'){
            if ((i <= len - 3) && (s[i+1] == 'C') && (s[i+2] == 'M')){
                sum += 910; i += 2;
            }
            else if ((i <= len - 2) && (s[i+1] == 'C')){
                sum += 90; i += 1;
            }
            else if ((i <= len - 2) && (s[i+1] == 'L')){
                sum += 40; i += 1;
            }
            else
                sum += 10;
        }
        else if (s[i] == 'C'){
            if ((i <= len - 2) && (s[i+1] == 'M')){
                sum += 900; i += 1;
            }
            else if ((i <= len - 2) && (s[i+1] == 'D')){
                sum += 400; i += 1;
            }
            else
                sum += 100;
        }
    }
    cout << sum;
    return 0;
}
