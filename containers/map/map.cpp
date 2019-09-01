#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
struct bst{
    struct node{
        node *left_child = nullptr, *right_child = nullptr, *parent = nullptr;
        T key;
        bool color = 0; //0 - black; 1 - red
        node(T k = 0) : key(k) {}
    };
    node *root, *nil = new node;

    bst(T a = 10){
        node* n = new node(a);
        n->left_child = n->right_child = n->parent = nil;
        root = n;
    }
    bst (int *a, int m) : bst(a[0]){
        for (int i = 1; i < m; i++)
            insert(a[i]);
    }

    node* find(T k){
        node* n = root;
        while (n != nil)
            if (k == n->key)
                return n;
            else if (k >= n->key)
                n = n->right_child;
            else if (k < n->key)
                n = n->left_child;
        return n;
    }
    node* max(node* n){
        while (n->right_child != nil)
            n = n->right_child;
        return n;
    }
    node* min(node* n){
        while (n->left_child != nil)
            n = n->left_child;
        return n;
    }
    void left_rotate(node *n){
        node *c = n->right_child;
        n->right_child = c->left_child;
        if (c->left_child != nil)
            c->left_child->parent = n;
        c->parent = n->parent;
        if (n->parent == nil)
            root = c;
        else if (n == n->parent->left_child)
            n->parent->left_child = c;
        else
            n->parent->right_child = c;
        c->left_child = n;
        n->parent = c;
    }
    void right_rotate(node *n){
        node *c = n->left_child;
        n->left_child = c->right_child;
        if (c->right_child != nil)
            c->right_child->parent = n;
        c->parent = n->parent;
        if (n->parent == nil)
            root = c;
        else if (n == n->parent->left_child)
            n->parent->left_child = c;
        else
            n->parent->right_child = c;
        c->right_child = n;
        n->parent = c;
    }
    void insert_fix_up(node* n){
        while (n->parent->color == 1)
            if (n->parent == n->parent->parent->left_child){
                node *uncle = n->parent->parent->right_child;
                if (uncle->color == 1){
                    n->parent->color = 0;
                    uncle->color = 0;
                    n->parent->parent->color = 1;
                    n = n->parent->parent;
                }
                else if (n == n->parent->right_child){
                    n = n->parent;
                    left_rotate(n);
                    n->parent->color = 0;
                    n->parent->parent->color = 1;
                    right_rotate(n->parent->parent);
                }
                else if (n == n->parent->left_child){
                    n->parent->color = 0;
                    n->parent->parent->color = 1;
                    right_rotate(n->parent->parent);
                }
            }
            else{
                node *uncle = n->parent->parent->left_child;
                if (uncle->color == 1){
                    n->parent->color = 0;
                    uncle->color = 0;
                    n->parent->parent->color = 1;
                    n = n->parent->parent;
                }
                else if (n == n->parent->left_child){
                    n = n->parent;
                    right_rotate(n);
                    n->parent->color = 0;
                    n->parent->parent->color = 1;
                    left_rotate(n->parent->parent);
                }
                else if (n == n->parent->right_child){
                    n->parent->color = 0;
                    n->parent->parent->color = 1;
                    left_rotate(n->parent->parent);
                }
            }
        root->color = 0;
    }
    void insert(T k){
        node *child = new node(k);
        child->parent = child->left_child = child->right_child = nil;
        node *n = root;
        while (child->parent == nil)
            if (child->key < n->key)
                if (n->left_child == nil){
                    child->parent = n;
                    n->left_child = child;
                }
                else
                    n = n->left_child;
            else
                if (n->right_child == nil){
                    child->parent = n;
                    n->right_child = child;
                }
                else
                    n = n->right_child;
        child->color = 1;
        insert_fix_up(child);
    }
    void transplant(node* subroot, node* reproot){
        if (subroot->parent == nil)
            root = reproot;
        else if(subroot->parent->left_child == subroot)
            subroot->parent->left_child = reproot;
        else
            subroot->parent->right_child = reproot;
        reproot->parent = subroot->parent;
    }
    void delete_fixup(node* n){
        while ((n != root) && (n->color == 0))
            if (n == n->parent->left_child){
                node *c = n->parent->right_child;
                if (c->color == 1){
                    c->color = 0;
                    n->parent->color = 1;
                    left_rotate(n->parent);
                    c = n->parent->right_child;
                }
                if ((c->left_child->color == 0) && (c->right_child->color == 0)){
                    c->color= 1;
                    n = n->parent;
                }
                else if (c->right_child->color == 0){
                    c->left_child->color = 0;
                    c->color = 1;
                    right_rotate(c);
                    c = n->parent->right_child;
                    c->color = n->parent->color;
                    n->parent->color = 0;
                    c->right_child->color = 0;
                    left_rotate(n->parent);
                    n = root;
                }
                else if (c->right_child->color == 0){
                    c->color = n->parent->color;
                    n->parent->color = 0;
                    c->right_child->color = 0;
                    left_rotate(n->parent);
                    n = root;
                }
            }
            else{
                node *c = n->parent->left_child;
                if (c->color == 1){
                    c->color = 0;
                    n->parent->color = 1;
                    right_rotate(n->parent);
                    c = n->parent->left_child;
                }
                if ((c->right_child->color == 0) && (c->left_child->color == 0)){
                    c->color= 1;
                    n = n->parent;
                }
                else if (c->left_child->color == 0){
                    c->right_child->color = 0;
                    c->color = 1;
                    left_rotate(c);
                    c = n->parent->left_child;
                    c->color = n->parent->color;
                    n->parent->color = 0;
                    c->left_child->color = 0;
                    right_rotate(n->parent);
                    n = root;
                }
                else if (c->left_child->color == 0){
                    c->color = n->parent->color;
                    n->parent->color = 0;
                    c->left_child->color = 0;
                    right_rotate(n->parent);
                    n = root;
                }
            }
        n->color = 0;
    }
    void delete_node(T k){
        node* n = find(k);
        if (n != nil){
            node *y = n, *x;
            bool y_color = y->color;
            if (n->left_child == nil){
                x = n->right_child;
                transplant(n, n->right_child);
            }
            else if (n->right_child == nil){
                x = n->left_child;
                transplant(n, n->left_child);
            }
            else {
                y = min(n->right_child);
                y_color = y->color;
                x = y->right_child;
                if (y->parent == n)
                    x->parent = y;
                else{
                    transplant(y, y->right_child);
                    y->right_child = n->right_child;
                    y->right_child->parent = y;
                }
                transplant(n, y);
                y->left_child = n->left_child;
                y->left_child->parent = y;
                y->color = n->color;
                if (y_color == 0)
                    delete_fixup(x);
            }
        }
        delete n;
    }
};

void print(bst<int> t, bst<int>::node* n){
    if (n->left_child != t.nil)
        print(t, n->left_child);
    cout << n->key << " ";
    if (n->right_child != t.nil)
        print(t, n->right_child);
}

int main(){
    int a[10] = {34, 2, 5, 8, 91, 5, 54, 27, 9, 5};
    bst<int> b(a, 10);
    b.delete_node(34);
    print(b, b.root);
    return 0;
}
