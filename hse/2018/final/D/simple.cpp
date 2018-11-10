#include <iostream>
using namespace std;

const int NLIM = 10;
int a[NLIM], n = NLIM;

void print(){
    for (int i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n");
}

int partition(int lo, int hi){
    int pivot = a[hi], i = lo;
    for (int j = lo; j < hi; j++)
        if (a[j] <= pivot)
            swap(a[j], a[i++]);
    swap(a[hi], a[i]);
//    print();
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
    for (int j = 0; j < 10; j++){
        for (int i = 0; i < n; i++)
            a[i] = rand() % 10;
        print();
        qsort(0, n - 1);
        print();
        printf("\n");
    }
    return 0;
}
