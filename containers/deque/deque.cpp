#include <iostream>
//#include <deque>
using namespace std;

template <typename T>
struct deque{
    int chunk_size = 5, chunk_cluster_size = 1;
    T **chunk_cluster = new T*[chunk_cluster_size];
    int fst = 0, lst = 1;
    deque(){
        for (int i = 0; i < chunk_cluster_size; i++)
            chunk_cluster[i] = new T[chunk_cluster_size];
    }
    int& operator[](int r){ return chunk_cluster[(r + fst) / chunk_size][r + fst - (r + fst)/chunk_size*chunk_size]; }
    void push_back(T i){
        if (lst < chunk_size)
            chunk_cluster[chunk_cluster_size - 1][lst++] = i;
        else{
            T** tmp = new T*[++chunk_cluster_size];
            for (int j = 0; j < chunk_cluster_size - 1; j++)
                tmp[j] = chunk_cluster[j];
            tmp[chunk_cluster_size-1] = new T[chunk_size];
            chunk_cluster = tmp;
            lst = 0;
            chunk_cluster[chunk_cluster_size - 1][lst++] = i;
        }
    }
    void push_front(T i){
        if (fst >= 0)
            chunk_cluster[0][fst--] = i;
        else{
            T** tmp = new T*[++chunk_cluster_size];
            for (int j = 1; j < chunk_cluster_size; j++)
                tmp[j] = chunk_cluster[j - 1];
            tmp[0] = new T[chunk_size];
            chunk_cluster = tmp;
            fst = chunk_size - 1;
            chunk_cluster[0][fst--] = i;
        }
    }
    void pop_back(){
        if (lst >= 0)
            lst--;
        else{
            delete[] chunk_cluster[chunk_cluster_size-- - 1];
            lst = 6;
        }
    }
    void pop_front(){
        if (fst < chunk_size)
            fst++;
        else{
            delete[] chunk_cluster[0];
            T** tmp = new int*[--chunk_cluster_size];
            for (int i = 1; i < chunk_cluster_size + 1; i++)
                tmp[i - 1] = chunk_cluster[i];
            chunk_cluster = tmp;
            fst = 0;
        }
    }
};

int main(){
    deque<int> deq;
    for (int i = 0; i < 20; i++)
        deq.push_back(i);
    for (int i = -1; i > -16; i--)
        deq.push_front(i);
    for (int i = 0; i < 35; i++)
        cout << deq[i] << " ";
    return 0;
}
