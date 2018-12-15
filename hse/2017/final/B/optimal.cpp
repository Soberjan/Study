#include <iostream>
#include <algorithm>

using namespace std;
const int NLIM = 10e5;
int n, a[NLIM];

int count(int lo, int hi, int m){
    int s = 0;
    for (int i = lo + 1; i < hi; i++)
        s+=m-a[i];
    return s;
}

int count1(int lo, int hi, int m){
    int s = 0;
    for (int i = lo; i < hi; i++)
        s+=m-a[i];
    return s;
}

int findmax(int lo, int hi){
    int m = 0;
    for (int i = lo; i < hi; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}

int findmax1(int lo, int hi){
    int m = 0;
    for (int i = lo + 1; i < hi; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}

pair<int, int> partition(int lo, int hi, int max){
    pair<int, int> p;
    for (int i = lo; i < hi; i++)
    if (a[i] == max){
        p.first = i;
        break;
    }
    for (int i = hi - 1; i >= 0; i--)
    if (a[i] == max){
        p.second = i;
        break;
    }
    return p;
}

int territoryleft(int lo, int hi){
    if (lo < hi){
        int max = findmax(lo, hi);
        int first;
        for (int i = lo; i < hi; i++)
        if (a[i] == max){
            first = i;
            break;
        }
        int s = territoryleft(lo, first);
        s += count (first, hi, max);
        return s;
    }
    else return 0;
}

int territoryright(int lo, int hi){
    if (lo < hi - 1){
        int max = findmax1(lo, hi);
        int last;
        for (int i = hi - 1; i >= lo; i--)
        if (a[i] == max){
            last = i;
            break;
        }
        int s = territoryright(last, hi);
        s += count1(lo, last + 1, max);
        return s;
    }
    else return 0;
}

int optimal(){
    int max = findmax(0, n);
    pair<int, int> p = partition(0, n, max);
    int sum = count(p.first, p.second, max);
    sum += territoryleft(0, p.first);
    sum += territoryright(p.second + 1, n);
    return sum;
}

int main(){
    //freopen("tests\\01", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << optimal();

    return 0;
}
