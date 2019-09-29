#include <iostream>
#include <bitset>
using namespace std;

void print(bitset<202> lbank, bitset<202> rbank, int len){
    for (int i = 0; i < len; i++)
        cout << lbank[i];
    cout << "\n";
    for (int i = 0; i < len; i++)
        cout << rbank[i];
    cout << "\n";
}

int count(bitset<202> bs, int i1, int i2){
    int sum = 1;
    for (int i = i1; i < i2; i++ )
        sum += bs[i];
    return sum;
}

int FindNextZ(bitset<202> bs, int i){
    while (bs[i] != 0)
        i++;
    return i;
}

int main()
{
//    freopen("tests/00", "r", stdin);
    string river;
    cin >> river;

    int len = (int)river.size() + 2;
    bitset<202> lbank; bitset<202> rbank;
    for (int i = 0; i < len - 2; i++)
        if (river[i] == 'L')
            lbank[i + 1] = 1;
        else if (river[i] == 'B')
            lbank[i+1] = rbank[i+1] = 1;
        else if (river[i] == 'R')
            rbank[i+1] = 1;
    //print(lbank, rbank, len);

    char bank = 'l'; int trans = 0;
    for ( int i1 = lbank._Find_first(), i2 = FindNextZ(lbank, i1); i1 != 202 ; ){
        int s1 = i2 - i1;
        int s2 = bank == 'l' ? count(rbank, i1, i2) : count(lbank, i1, i2);
        if (s2 < s1){
            bank = bank == 'l' ? 'r' : 'l';
            i1 = bank == 'l' ? lbank._Find_next(i2 - 1) : rbank._Find_next(i2 - 1);
            i2 = bank == 'l' ? FindNextZ(lbank, i1) : FindNextZ(rbank, i1);
            trans += s2;
        }
        else{
            trans += s1;
            i1 = bank == 'l' ? lbank._Find_next(i2) : rbank._Find_next(i2);
            i2 = bank == 'l' ? FindNextZ(lbank, i1) : FindNextZ(rbank, i1);
        }
    }
    trans = bank == 'l' ? trans+1 : trans;

    cout << trans;
    return 0;
}
