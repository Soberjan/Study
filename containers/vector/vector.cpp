#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
struct MyVector{
    int size = 0, capacity = 0;
    T *a = new T[capacity];
    struct iterator{
        T *p;
        bool operator!=(MyVector::iterator r){ return p != r.p; }
        T operator*(){ return *p; }
        MyVector::iterator operator++(){ p++; return *this; }
    };
    MyVector(){
        size = 0;
        capacity = 4;
    }
    iterator begin(){
        iterator it;
        it.p = a;
        return it;
    }
    iterator end(){
        iterator it;
        it.p = a + size;
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
    int get_value(int id){ return a[id]; }

    T& operator[](int id){
        return *(a + id);
    }
};

//template<class T> bool operator!=(MyVector::iterator l, MyVector::iterator r){
//    return l.p != r.p;
//}
//template<class T> T operator*(MyVector::iterator& l){
//    return *l.p;
//}
//MyVector::iterator& operator++(MyVector::iterator& l){
//    l.p++;
//    return l;
//}

int main()
{
    MyVector<int> v;
    for (int i = 0; i < 130; i++)
        v.push_back(i);
    v[0] = 123123;
    for (MyVector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n" << v.size << " " << v.capacity;
    return 0;
}
