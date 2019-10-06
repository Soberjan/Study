#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

struct deque{
    int capacity, size, fst, lst;
    int *a;
    deque() : capacity(8), size(0){}

    void push_back(int r){
        if (size == 0){
            a = new int[capacity];
            a[capacity/2] = r;
            fst = lst = capacity / 2;
            size = 1;
        }
        else if (size != capacity){
            lst = lst == capacity - 1 ? 0 : lst + 1;
            a[lst] = r;
            size++;
        }
        else{
            capacity *= 2;
            int *tmp = new int[capacity];
            memcpy(tmp + capacity/4, a + fst, sizeof(int) * (size - fst));
            memcpy(tmp + capacity/4 + (size-fst), a, sizeof(int) * (lst + 1));
            delete[] a;
            a = tmp;
            fst = capacity/4;
            lst = fst + size;
            a[lst] = r;
            size++;
        }
    }
};

int main(){
    deque d;
    for (int i = 0; i < 100000000; i++)
        d.push_back(i);
    cout << clock()/1000.0;
    return 0;
}
