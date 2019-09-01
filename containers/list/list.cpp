#include <iostream>
//#include <list>
using namespace std;

template <typename T>
struct list{
    struct node{
        node *next = nullptr, *prev = nullptr;
        T key;
        node(T k) : key(k) { }
    };
    list(){}
    list(int* a, int m){ for (int i = 0; i < m; insert(a[i]), i++); }
    struct iterator {
        node* it;
        iterator(node* i){ it = i; }
        void operator++(){ it = it->next; }
        void operator--(){ it = it->prev; }
        bool operator!=(list::iterator r){ return it != r.it;}
        T operator*(){ return it->key; }
    };
    iterator begin(){ iterator it(head); return it; }
    iterator end(){ iterator it(tail->next); return it; }
    node *head = nullptr, *tail;
    node* find(T k){
        iterator it = begin();
        while ((it != end()) && (*it != k))
            ++it;
        if (it != end())
            return it.it;
        return nullptr;
    }
    void insert(T k){
        if (head == nullptr){
            head = new node(k);
            tail = head;
        }
        else{
            node *n = new node(k);
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void erase(T k){
        node *n = find(k);
        if (n != nullptr){
            if ((n->next == nullptr) && (n->prev == nullptr))
                delete n;
            else if (n->next == nullptr){
                n->prev->next = nullptr;
                tail = n->prev;
                delete n;
            }
            else if (n->prev == nullptr){
                n->next->prev = nullptr;
                head = n->next;
                delete n;
            }
            else{
                n->next->prev = n->prev;
                n->prev->next = n->next;
                delete n;
            }
        }
    }
};

int main()
{
    int a[5] = {1, 21, 32, 3, 54};
    list<int> l(a, 5); //работа конструктора в std отличается, поэтому include не работает
    l.find(100);
    l.erase(32);
    l.erase(54);
    l.erase(1);
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    return 0;
}
