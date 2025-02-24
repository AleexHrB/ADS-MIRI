#include "bst.hh"
#include <iostream>
using namespace std;


BST::BST() {
    root = nullptr;
}

void BST::insert(unsigned int x) {
    root = insert(x, root);
}

void BST::erase(unsigned int x) {
    root = erase(x, root);
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

bool BST::find(unsigned int x) {
    return find(x, root);
}

bool BST::find(unsigned int x, node* n) {
    if (n == nullptr) return false;
    if (n -> x == x) return true;
    if (n -> x > x) return find(x, n->l);
    else return find(x, n->r);
}

BST::node* BST::insert(unsigned int x, node* n) {

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

BST::node* BST::erase(unsigned int x, node* n) {

    if (n == nullptr) return nullptr;

    if (n -> x > x) {
        n -> l = erase(x, n-> l);
        return n;
    }

    if (n -> x < x) {
        n -> r = erase(x, n-> r);
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

    node* newVal = n -> r;
    while (newVal -> l != nullptr) newVal = newVal -> l;
    n -> x = newVal -> x;
    n -> r = erase(x,n -> r);
    return n;
}
