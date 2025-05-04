#include "bst.hh"
#include <queue>
using namespace std;


BST::BST() {
    root = nullptr;
}

BST::~BST() {
    freeMemory(root);
}

void BST::erase(float x) {
    root = erase(root, x);
}

BST::node* BST::erase(node* n, float x) {

    if (n == nullptr) return nullptr;

    if (n -> x < x) {
        n -> r = erase(n -> r, x);
        return n;
    }

    if (n -> x > x) {
        n -> l = erase(n -> l, x);
        return n;
    }

    if (n -> l == nullptr) {
        node* aux = n -> r;
        delete n;
        return aux;
    }

    if (n -> r == nullptr) {
        node* aux = n -> l;
        delete n;
        return aux;
    }

    float val = 0;
    n -> r  = eraseSuccessor(n -> r, val);
    n -> x = val;
    return n;
}

BST::node* BST::eraseSuccessor(node* n, float& x) {
    
    if (n -> l == nullptr) {
        node* aux = n -> r;
        x = n -> x;
        delete n;
        return aux;
    }

    else {
        n -> l = eraseSuccessor(n -> l, x);
        return n;
    }
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
