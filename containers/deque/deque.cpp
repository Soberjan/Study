#include <iostream>
//#include <deque>
using namespace std;

template <typename T>
struct deque{
    int chunk_size = 6, chunk_claster_size = 2;
    T **chunk_claster = new T*[chunk_claster_size];
    int front = 0, fst = 0;
    //struct iterator{ int it; };
    //iterator back = 0;
    deque(){
        for (int i = 0; i < chunk_claster_size; i++)
            chunk_claster[i] = new T[chunk_claster_size];
    }
    int& operator[](int r){ return chunk_claster[(r + fst) / chunk_size][r + fst - (r + fst)/chunk_size*chunk_size]; }
//    void push_back(T i){
//        back++;
//    }
//    void push_front(){
//        front--;
//    }
//    void pop_back(){
//        back--;
//    }
//    void pop_front(){
//        front++;
//    }
};

int main()
{
    deque<int> deq;
    deq[0] = deq[1] = 3;
    cout << deq[0] << deq[1];

    return 0;
}
