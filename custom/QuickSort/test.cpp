#include <iostream>
using namespace std;

const int NLIM = 20;
int a[NLIM];

void print(int lo, int hi){
    for (int i = 0; i < NLIM; i++)
        cout << a[i] << " ";
    cout << "\n";
    }

int partition(int lo, int hi){
    int pivot = a[hi], i = lo;
    for (int j = lo; j <= hi - 1; j++){
        if (a[j] <= pivot)
            swap(a[j], a[i++]);
        }
    swap(a[i], a[hi]);
    //print(lo, hi);
    return i;
    }

void qsort(int lo, int hi){
    int p;
    if (lo < hi){
        p = partition(lo, hi);
        qsort(lo, p - 1);
        qsort(p + 1, hi);
    }
}


int main()
{
    for (int i = 0; i < NLIM; i++)
        a[i] = rand() / 100;
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < NLIM; j++)
            a[j] = rand() % 10;
        qsort(0, NLIM);
        for (int j = 0; j < NLIM - 1; j++)
            if (a[j] > a[j + 1])
              cout << "error!";
    }
    cout << "done!";    return 0;
}
