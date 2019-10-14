#include <iostream>
#include <deque>
#include <ctime>
using namespace std;

int main(){
    deque<int> d;
    for (int i = 0; i < 100000000; i++)
        d.push_back(i);
    cout << clock()/1000.0;
    return 0;
}
