#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
struct MyVector{
    int size, capacity;
    T *a = new T[capacity];
    struct iterator{
        T *p;
        iterator(int *a, int add = 0){ p = a + add; }
        bool operator!=(MyVector::iterator r){ return p != r.p; }
        T operator*(){ return *p; }
        MyVector::iterator operator++(){ p++; return *this; }
    };

    MyVector(): size(0), capacity(2){}
    MyVector(int n): size(0), capacity(n){}

    iterator begin(){
        iterator it(a, 0);
        return it;
    }
    iterator end(){
        iterator it(a, size);
        return it;
    }
    void push_back(T i){
        if (size < capacity)
            a[size++] = i;
        else if (size == capacity){
            capacity *= 2;
            T *b = new T[capacity];
            memcpy(b, a, 4 * capacity);
            delete[] a;
            a = b;
            a[size++] = i;
        }
    }
    T& operator[](int id){
        return *(a + id);
    }
};

int main()
{
    MyVector<int> v(16);
    for (int i = 0; i < 130; i++)
        v.push_back(i);
    v[0] = 123123;
    for (MyVector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n" << v.size << " " << v.capacity;
    return 0;
}
