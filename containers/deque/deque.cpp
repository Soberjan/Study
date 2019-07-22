#include <iostream>
//#include <deque>
using namespace std;

template <typename T>
struct deque{
    int chunk_size = 6, chunk_claster_size = 2;
    T **chunk_claster = new T*[chunk_claster_size];
    int back = 0, front = 0;
    struct iterator{ int it; };
    deque(int new_size){
        for (int i = 0; i < new_size; i++)
            chunk_claster[i] = new T[chunk_size];
    }
    void push_back(T i){
        back++;
    }
    void push_front(){
        front--;
    }
    void pop_back(){
        back--;
    }
    void pop_front(){
        front++;
    }
};

int main()
{
//    deque<int> deq;
//    for (int i = 0; i < 51; i++)
//        deq.push_back(i);
//    for (int i = -1; i > -51; i--)
//        deq.push_front(i);
//    for (int i = 0; i < 21; i++)
//        deq.pop_back();
//    for (int i = 0; i < 21; i++)
//        deq.pop_front();
//    deq[0] = 101;
//    for (deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
//        cout << *it << " ";

    return 0;
}
