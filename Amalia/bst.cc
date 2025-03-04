#include "bst.hh"
#include <iostream>
#include <queue>
using namespace std;


BST::BST() {
    root = nullptr;
}

BST::~BST() {
    freeMemory(root);
}

unsigned int BST::ipl() {
    queue<pair<node*,unsigned int>> q;
    unsigned int iplLocal = 0;
    q.push({root,0});

    while (not q.empty()) {
        pair<node*, unsigned int> p = q.front();
        q.pop();

        if (p.first != nullptr) {
            unsigned int d = p.second;
            iplLocal += d;
            q.push({p.first -> l, d+1});
            q.push({p.first -> r, d+1});
        }
    }

    return iplLocal;
}

void BST::freeMemory(node* n) {

    if (n != nullptr) {
        freeMemory(n -> l);
        freeMemory(n -> r);
        delete n;
    }
}

void BST::insert(float x) {
    root = insert(x, root);
}

void BST::print() {
    print(root);
}

void BST::print(node* n) {
    if (n != nullptr) {
        print(n -> l);
        cout << n -> x << endl;
        print(n -> r);
    }
}

unsigned int BST::find(float x) {
    return find(x, root);
}

unsigned int BST::find(float x, node* n) {
    if (n == nullptr) return 0;
    if (n -> x == x) return 1;
    if (n -> x > x) return 1 + find(x, n->l);
    else return 1 + find(x, n->r);
}

BST::node* BST::insert(float x, node* n) {

    if (n == nullptr) {
        node* newNode = new node;
        newNode -> x = x;
        return newNode;
    }

    else if (n -> x == x) return n;

    else {
        if (n -> x > x) n -> l = insert(x, n -> l);
        else n -> r = insert(x, n -> r);
        return n;
    }
}
