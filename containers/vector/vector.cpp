#include <iostream>
#include <cstring>
using namespace std;

struct MyVector{
    int size = 0, capacity = 4;
    int *a = new int[capacity];
    void push_back(int i){
        if (size < capacity)
            a[size++] = i;
        else if (size == capacity){
            int *b = new int[capacity];
            memcpy(b, a, 4 * capacity);
            capacity *= 2;
            delete[] a;
            a = new int[capacity];
            memcpy(a, b, 4 * capacity);
            a[size++] = i;
        }
    }
    void change(int id, int value){
        a[id] = value;
    }
    int get_value(int id){
        return a[id];
    }
};

int main()
{
    MyVector v;
    for (int i = 0; i < 130; i++)
        v.push_back(i);
    v.change(0, 123123);
    for (int i = 0; i < 130; i++)
        cout << v.get_value(i) << " ";
    cout << "\n" << v.size << " " << v.capacity; //провер€ю, правильно ли расшир€етс€ вектор на больших значыени€х
    return 0;
}
