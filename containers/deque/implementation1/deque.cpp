#include <iostream>
//#include <deque>
using namespace std;

template <typename T>
struct deque{
    int chunk_size = 3, cluster_size = 1, sze = 0;
    T **cluster = new T*[cluster_size]; // двумерный массив, в котором хран€тс€ указатели на чанки.
    int fst = 0, lst = 0; // позиции в чанке первого и последнего элемента соответственного в соответствующих им чанках
    struct iterator{
        T *p, **c; // в итераторе храним cluster дл€ того, чтобы правильно работал оператор "++"
        int pos, loc, s;
        iterator(int *a, int **b, int s, int p, int l) : p(a), c(b), pos(p), loc(l), s(s) {};
        bool operator!=(deque::iterator r){ return p != r.p; }
        T operator*(){ return *p; }
        deque::iterator operator++(){
            if (pos < s - 1){
                pos++;
                p++;
            }
            else{
                pos = 0;
                loc++;
                p = &c[loc][0];
            }
            return *this;
        }
    };
    deque(){
        cluster[0] = new T[chunk_size]; // конструктор пустого дека
    }
    int size(){ return sze; }
    iterator begin(){
        iterator it(&cluster[0][fst], cluster, chunk_size, fst, 0);
        return it;
    }
    iterator end(){
        iterator it(&cluster[cluster_size - 1][lst + 1], cluster, chunk_size, lst, chunk_size - 1);
        return it;
    }
    int& operator[](int r){
        int n = r - (chunk_size - fst);
        int p = n < 0 ? 0 : 1 + n/chunk_size;
        int q = n < 0 ? fst + r : n % chunk_size;
        return cluster[p][q];
    }
    void push_back(T i){ // функци€, вставл€юща€ элемент в конец дека
        if (sze == 0)
            cluster[0][lst] = i;
        else if (lst < chunk_size - 1)
            cluster[cluster_size - 1][++lst] = i;
        else{
            T** tmp = new T*[++cluster_size];
            for (int j = 0; j < cluster_size - 1; j++)
                tmp[j] = cluster[j];
            tmp[cluster_size-1] = new T[chunk_size];
            cluster = tmp;
            lst = 0;
            cluster[cluster_size - 1][0] = i;
        }
        sze++;
    }
    void push_front(int i){ // функци€, вставл€юща€ элемент в начало дека
        if (sze == 0)
            cluster[0][fst] = i;
        else if (fst > 0)
            cluster[0][--fst] = i;
        else{
            T** tmp = new T*[++cluster_size];
            for (int j = 1; j < cluster_size; j++)
                tmp[j] = cluster[j - 1];
            tmp[0] = new T[chunk_size];
            cluster = tmp;
            fst = chunk_size - 1;
            cluster[0][fst] = i;
        }
        sze++;
    }
    void pop_back(){ // функци€, удал€юща€ элемент из конца дека
        lst--;
        sze--;
        if (lst < 0){
            delete[] cluster[cluster_size-- - 1];
            lst = chunk_size - 1;
        }
    }
    void pop_front(){ // функци€, удал€юща€ элемент из начала дека
        fst++;
        sze--;
        if (fst >= chunk_size){
            delete[] cluster[0];
            int** tmp = new int*[--cluster_size];
            for (int i = 1; i < cluster_size + 1; i++)
                tmp[i - 1] = cluster[i];
            cluster = tmp;
            fst = 0;
        }
    }
};

int main(){
    deque<int> deq;
    for (int i = 0; i < 20; i++)
        deq.push_back(i);
    for (int i = 0; i < 5; i++)
        deq.pop_back();
    for (int i = 0; i < 20; i++)
        deq.push_back(i);
    for (int i = -1; i > -20; i--)
        deq.push_front(i);
    for (int i = 0; i < 5; i++)
        deq.pop_front();
    for (int i = -1; i > -20; i--)
        deq.push_front(i);
    for (int i = 0; i < deq.size(); i++)
        cout << deq[i] << " ";
    cout << "\n\n";
    for (deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        cout << *it << " ";
    return 0;
}
