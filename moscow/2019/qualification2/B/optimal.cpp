#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <locale>
using namespace std;
#define ll long long

//double minfloat(vector<string> words){
//    return (min(min(a[0])))
//}

//string minword(vector<string> words){
//return 0;
//}
//
//int minint(vector<string> words){
//return ni;
//}

string simple(string line){
    vector<string> words;
    istringstream iss(line);
    string word;
    while (getline(iss, word, '\t'))
        words.push_back(word);
    bool fl, wd;
    for(int i = 0; i < line.size(), fl==0, wd==0; i++)
        if (line[i]=='.')
            fl = 1;
        else if (isalpha(line[i]))
            wd = 1;
//    if (fl)
//        return minfloat(vector<string> words)
//    if (wd)
//        return minword(vector<string> words)
//    return minint
}

int main()
{
    freopen("tests/00", "r", stdin);
    string line;
//    while (getline(cin, line))
//        cout << simple(line) << endl;
//    string str = "afaf  adf as asdf";
//    string word;
//    istringstream words(str);
//    getline(words, word, '\t');
//    cout << word;
    string a = "AB";
    string b = "12";
    cout << a.compare(b);
    return 0;
}
