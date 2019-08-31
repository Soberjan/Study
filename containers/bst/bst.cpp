#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
struct bst{
    struct node{
        node* left_child = nullptr, *right_child = nullptr, *parent = nullptr;
        T key;
        node(T k = 0) : key(k) {}
    };
    node* root;

    bst(T a = 10){
        node* n = new node(a);
        root = n;
    }
    void bsth(int *a, int n, int m){
        if (n <= m){
            insert(a[n + (m - n) / 2]);
            bsth(a, n, n + (m - n)/2 - 1);
            bsth(a, n + (m - n)/2 + 1, m);
        }
    }
    bst (int *a, int n){
        sort(a, a + n);
        node* nd = new node(a[n / 2]);
        root = nd;
        bsth(a, 0, n / 2 - 1);
        bsth(a, n / 2 + 1, n - 1);
    }

    node* find(T k){
        node* n = root;
        while (n != nullptr)
            if (k == n->key)
                return n;
            else if (k >= n->key)
                n = n->right_child;
            else if (k < n->key)
                n = n->left_child;
        return n;
    }
    node* max(){
        node* n = root;
        while (n->right_child != nullptr)
            n = n->right_child;
        return n;
    }
    node* min(){
        node* n = root;
        while (n->left_child != nullptr)
            n = n->left_child;
        return n;
    }
    void insert(T k){
        node *child = new node(k);
        node *n = root;
        while (child->parent == nullptr)
            if (child->key < n->key)
                if (n->left_child == nullptr){
                    child->parent = n;
                    n->left_child = child;
                }
                else
                    n = n->left_child;
            else
                if (n->right_child == nullptr){
                    child->parent = n;
                    n->right_child = child;
                }
                else
                    n = n->right_child;
    }
    void transplant(node* subroot, node* reproot){
        if (subroot == root)
            root = reproot;
        else if(subroot->parent->left_child == subroot)
            subroot->parent->left_child = reproot;
        else
            subroot->parent->right_child = reproot;
        if (reproot != nullptr)
            reproot->parent = subroot->parent;
    }
    void delete_node(T k){
        node* n = find(k);
        if (n != nullptr){
            if (n->left_child == nullptr)
                transplant(n, n->right_child);
            else if (n->right_child == nullptr)
                transplant(n, n->left_child);
            else{
                node* rep = n->right_child;
                while (rep->left_child != nullptr)
                    rep = rep->left_child;
                if (rep->parent != n){
                    transplant(rep, rep->right_child);
                    rep->right_child = n->right_child;
                    rep->right_child->parent = rep;
                }
                transplant(n, rep);
                rep->left_child = n->left_child;
                rep->left_child->parent = rep;
            }
        }
        delete n;
    }
};

void print(bst<int>::node* n){
    if (n->left_child != nullptr)
        print(n->left_child);
    cout << n->key << " ";
    if (n->right_child != nullptr)
        print(n->right_child);
}

int main(){
    int a[10] = {34, 2, 5, 8, 91, 5, 54, 27, 9, 5};
    bst<int> b(a, 10);
    print(b.root);
    cout << "\n";
    b.delete_node(9);
    print(b.root);
    return 0;
}
