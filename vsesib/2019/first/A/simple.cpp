#include <iostream>
#include <map>
#include <list>
#include <cmath>
using namespace std;

int n, *p = new int [100000];

void primes(int n, list<int>& c){
    if (n % 2 == 0)
        c.push_back(2);
    while (n % 2 == 0)
        n /= 2;
    for (int i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0)
            c.push_back(i);
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        c.push_back(n);
}

list<int> cross(list<int>& a, list<int>& b){
    list<int> c;
    for (list<int>::iterator i = a.begin(); i != a.end(); ++i)
        for (list<int>::iterator j = b.begin(); j != b.end(); ++j)
            if (*i == *j)
                c.push_back(*i);
    return c;
}

void print(list<int> a){
    for (list<int>::iterator i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";
    cout << "\n";
}

int main()
{
    //freopen("tests/05", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int *a = new int[n];
    map<int, list<int>> b;
    b[0] = list<int>(0);
    b[1] = list<int>(0);
    b[2] = list<int>(0);
    for (int i = 0; i < n; i++){
        if (p[i] == 1){
            cout << "Impossible";
            exit(0);
        }
        list<int> c;
        primes(p[i], c);
        bool crossed = 0;
        for (int j = 0; j < 3; j++){
            if (b[j].empty()){
                b[j] = c;
                a[i] = j;
                crossed = 1;
                break;
            }
            list<int> d = cross(b[j], c);
            if (!d.empty()){
                b[j] = d;
                a[i] = j;
                crossed = 1;
                break;
            }
        }
        if (!crossed){
            cout << "Impossible";
            exit(0);
        }
    }
    cout << "Possible" << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] + 1 << " ";

    return 0;
}
