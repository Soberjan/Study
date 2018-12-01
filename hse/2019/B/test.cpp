#include <iostream>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <map>
using namespace std;

int n, a[100001];

int optimal(){
    map<int, int> partic;
    for (int i = 0; i < n; i++)
        partic[a[i]] += 1;

    int s = 0;
    for(map<int,int>::iterator it=partic.begin(); it!=partic.end(); ++it){
        int x = it->first;
        int y = it->second;
        s += y/x*x;
        //cout << x << " " << y << " " << s << "\n";
    }
    return s;
    }

int simple(){
    sort(a, a + n);
    int s = 0, q = 1;
    for (int i = 0; i < n; i++){
        if ((a[i] < a[i + 1]) || (a[i + 1] == 0)){
            s += (q / a[i])*a[i];
            q = 1;
        } else q++;
    }
    return s;
    }

int main()
{
    srand(time(0));
    for (int i = 0; i < 10000; i++){
        n = rand() % 20 + 5;
        for (int j = 0; j < n; j++)
            a[j] = rand() % 20 + 1;

        if(simple() != optimal())
            cout << "error!";
    }
    cout << "done!";
    return 0;
}
