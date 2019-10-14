#include <iostream>
#include <cstring>
//#include <deque>
using namespace std;

template <typename T>
struct deque{
    int chunk_size = 3, cluster_size = 1;
    T ** cluster = new T*[cluster_size]; // массив указателей на чанки (реализован как циклический буфер)
    int fst = 1, nxt = 1; // индексы в чанках начала и следующего после конца в очереди
    int head = 0, tail = 0; // индексы в кластере чанков начала и конца очереди

    struct iterator{
        deque *outer;
        int i, j; T *it;
        iterator (deque *out, int a, int b) { outer = out, i = a, j = b; it = outer->&cluster[i][j]; }
        bool operator!=(deque::iterator r) { return r.it != it; }
        T operator*() { return *it; }
        deque::iterator operator++(){
            if (j == outer->chunk_size){
                j =-1;
                i++;
            }
            j++;
            it = cluster->i->j;
        }
    };

    deque(){
        cluster[0] = new T[chunk_size];
    }

    int size(){ return ( (cluster_size + tail - head) % cluster_size) * chunk_size - fst + nxt; }
    iterator begin(){
        iterator it(this, this->head, this->fst);
        return it;
    }
    iterator end(){
        iterator it(this, this->tail, this->lst);
        return it;
    }
    int& operator[](int idx){
        int n = idx + fst;
        int p = (head + n / chunk_size) % cluster_size;
        int q = n % chunk_size;
        return cluster[p][q];
    }

    void push_back(T v){
        if ( (nxt == chunk_size) && ( (tail + 1) % cluster_size == head ) )
            realloc(true);
        if (nxt == chunk_size) {
            tail = (tail + 1) % cluster_size;
            nxt = 0;
        }
        cluster[tail][nxt++] = v;
    }

    void push_front(T v){
        if ( (fst == 0) && ( (cluster_size + head - 1) % cluster_size == tail ) )
            realloc(true);
        if (fst == 0) {
            head = (cluster_size + head - 1) % cluster_size;
            fst = chunk_size;
        }
        cluster[head][--fst] = v;
    }

    void pop_back() {
        if ((fst == nxt) && (head == tail))
            return;
        if (nxt == 1){
            tail = (cluster_size + tail - 1) % cluster_size;
            nxt = chunk_size;
        }
        else
            nxt--;
        realloc(false);
    }

    void pop_front() {
        if ((fst == nxt) && (head == tail))
            return;
        if (fst == chunk_size - 1){
            head = (head + 1) % cluster_size;
            fst = 0;
        }
        else
            fst++;
        realloc(false);
    }

    void realloc(bool increase){
        if (!increase && (size() > cluster_size * chunk_size / 4) )
            return;
        int new_cluster_size = increase ? 2 * cluster_size : cluster_size / 2;
        T **new_cluster = new T*[new_cluster_size];
        if (tail > head)
            memcpy(new_cluster, cluster, sizeof(T) * (tail - head + 1) );
        else{
            memcpy(new_cluster, cluster + head, sizeof(T*) * (cluster_size - head) );
            memcpy(new_cluster + cluster_size - head, cluster, sizeof(T*) * (tail + 1) );
        }
        for (int i = cluster_size; i < new_cluster_size; i++)
            new_cluster[i] = new T[chunk_size];
        head = 0;
        tail = cluster_size - 1;
        cluster_size = new_cluster_size;
        delete[] cluster;
        cluster = new_cluster;
    }
};

int main(){
    deque<int> d;
    for (int i = 0; i < 20; i++)
        d.push_back(i);
    for (int i = -1; i > -20; i--)
        d.push_front(i);
    for (int i = 0; i < 5; i++)
        d.pop_back();
    for (int i = 0; i < 5; i++)
        d.pop_front();
//    for (int i = 0; i < d.size(); i++)
//        cout << d[i] << " ";
    deque<int>::iterator it = d.begin();
    return 0;
}
