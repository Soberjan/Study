#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct bst{
    struct node{
        node* left_child = nullptr, *right_child = nullptr, *parent = nullptr;
        T key;
        node(int k = 0) : key(k) {}
    };
//    struct iterator{
//
//    };

    vector<node> tree;

    bst(int a = 10){
        node root(a);
        tree.push_back(root);
    }
//    bst (T *a){ инициализация массивом - написать после изучения
//                self-balancing search tree
//    }

    node& bst_root(){
        return tree[0];
    }
    T max(){
        node n = tree[0];
        while (n.right_child != nullptr)
            n = n.right_child;
        return n.key;
    }
    T min(){
        node n = tree[0];
        while (n.left_child != nullptr)
            n = n.left_child;
        return n.key;
    }
    void bst_insert(int k){
        node *child = new node(k);
        node *n = &tree[0];
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
        tree.push_back(*child);
    }
};

void print(bst<int>::node n){
    if (n.left_child != nullptr)
        print(*n.left_child);
    cout << n.key << " ";
    if (n.right_child != nullptr)
        print(*n.right_child);
}

int main(){
    bst<int> LUL(100);
    LUL.bst_insert(123);
    LUL.bst_insert(8);
    LUL.bst_insert(5);
    print(LUL.bst_root());
    return 0;
}
