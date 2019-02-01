#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    string langs[10] = {"be", "de","en", "fr","hy", "it","ka", "ru","sv", "uk"};
//    for (int i = 0; i < 10; i++)
//        cout << langs[i];
    map <string, set<string>> dict;
    for (int i = 0; i < 10; i++){
        for (int j = 1; j < 101; j++){
            string buf = "TrSet/" + langs[i] + "/" + to_string(j) + ".txt";
            //cout << buf << ' ';
            char buff[100];
            for (int q = 0; q < (int)buf.size(); q++)
                buff[q] = buf [q];
            buff[(int)buf.size()] = '\0';
            //cout << buff;
            freopen(buff, "r", stdin);

            //cout << langs[i];
            string useless;
            while (cin >> useless){
                cout << useless;
                dict[langs[i]].insert(useless);
            }

            fclose(stdin);
        }
        for (set<string>::iterator q = dict[langs[i]].begin(); q != dict[langs[i]].end(); ++q)
            cout << *q << " ";
            cout << '\n' << '\n';
    }

    return 0;
}
