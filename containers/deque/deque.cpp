#include <iostream>
//#include <deque>
using namespace std;

struct deque{
    int chunk_size = 3, chunk_cluster_size = 1;
    int **chunk_cluster = new int*[chunk_cluster_size];
    int fst = 0, lst = 0;
    deque(int r){
        for (int i = 0; i < chunk_cluster_size; i++)
            chunk_cluster[i] = new int[chunk_size];
        chunk_cluster[0][0] = r;
    }
    int& operator[](int r){
        int n = r - (chunk_size - fst);
        int p = n < 0 ? 0 : 1 + n/chunk_size;
        int q = n < 0 ? fst + r : n % chunk_size;
        return chunk_cluster[p][q];
    }
    void push_back(int i){
        if (lst < chunk_size - 1){
            chunk_cluster[chunk_cluster_size - 1][++lst] = i;
        }
        else{
            int** tmp = new int*[++chunk_cluster_size];
            for (int j = 0; j < chunk_cluster_size - 1; j++)
                tmp[j] = chunk_cluster[j];
            tmp[chunk_cluster_size-1] = new int[chunk_size];
            chunk_cluster = tmp;
            lst = 0;
            chunk_cluster[chunk_cluster_size - 1][0] = i;
        }
    }
    void push_front(int i){
        if (fst > 0)
            chunk_cluster[0][--fst] = i;
        else{
            int** tmp = new int*[++chunk_cluster_size];
            for (int j = 1; j < chunk_cluster_size; j++)
                tmp[j] = chunk_cluster[j - 1];
            tmp[0] = new int[chunk_size];
            chunk_cluster = tmp;
            fst = chunk_size - 1;
            chunk_cluster[0][fst] = i;
        }
    }
    void pop_back(){
        lst--;
        if (lst < 0){
            delete[] chunk_cluster[chunk_cluster_size-- - 1];
            lst = chunk_size - 1;
        }
    }
    void pop_front(){
        fst++;
        if (fst >= chunk_size){
            delete[] chunk_cluster[0];
            int** tmp = new int*[--chunk_cluster_size];
            for (int i = 1; i < chunk_cluster_size + 1; i++)
                tmp[i - 1] = chunk_cluster[i];
            chunk_cluster = tmp;
            fst = 0;
        }
    }
};

int main(){
    deque deq(0);
    for (int i = 1; i < 21; i++)
        deq.push_back(i);
    for (int i = -1; i > -21; i--)
        deq.push_front(i);
    for (int i = 0; i  < 10; i++)
        deq.pop_back();
    for (int i = 0; i  < 10; i++)
        deq.pop_front();
    deq[0] = 123123;
    for (int i = 0; i < 21; i++)
        cout << deq[i] << " ";
    return 0;
}
