#include <iostream>
#include <cstring>
using namespace std;

struct MyVector{
    struct iterator{
        int *p;
        bool operator!=(iterator& it){
            return (&p != &it.p);
        }
        bool operator*(){
            return *p;
        }
        iterator& operator++(){
            p++;
            return *this;
        }
    };
    int size = 0, capacity = 4;
    int *a = new int[capacity];
    iterator& begin(){
        iterator it;
        it.p = a;
        return it;
    }
    iterator& end(){
        iterator it;
        it.p = a + size;
        return it;
    }
    void push_back(int i){
        if (size < capacity)
            a[size++] = i;
        else if (size == capacity){
            capacity *= 2;
            int *b = new int[capacity];
            memcpy(b, a, 4 * capacity);
            int *f = a;
            a = b;
            b = f;
            delete[] b;
            a[size++] = i;
        }
    }
    void change(int id, int value){ a[id] = value; }
    int get_value(int id){ return a[id]; }

    int* operator[](int id){
        int *q = a + id;
        return q;
    }
};

int main()
{
    MyVector v;
    for (int i = 0; i < 130; i++)
        v.push_back(i);
    v.change(0, 123123);
    for (MyVector::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n" << v.size << " " << v.capacity;
    return 0;
}
