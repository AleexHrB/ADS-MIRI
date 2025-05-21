#include <iostream>
using namespace std;

class Treap {

    public:

        void insert(unsigned int x, const string& s) {
            node* l,r;
            update(root, x);
            split(x,root, l, r);
            node* n = new node;
            n -> x = x;
            n -> s = s;
            root = merge(merge(l,n), r);
        }

    private:
        mt19937 rng;
        struct node {
            node* l = nullptr;
            node* r = nullptr;
            unsigned int prior = unsigned int(rng());
            unsigned int x;
            string s;
        }
        
        void update(node* p, unsigned int x) {
            if (p != nullptr and p -> x >= x) {
                ++(p -> x);
                update(p -> l, x);
                update(p -> r, x);
            }
        }

        unsigned int size(node* p) {
            return p == nullptr ? 0 : p -> counter;
        }

        void split(unsigned int x, node* p, node*& l, node*& r) {
            if (p == nullptr) l = r = nullptr;
            else if (p->x < x) {
                split(x,p->r, p->r, r);
            }
            else if (p->x > x) split(x,p->l, l, p->l);
            else {
                l = p -> l;
                r = p -> r;
            }
        }

        node* merge(node* l, node* r) {
            if (l == nullptr) return r;
            if (r == nullptr) return l;
            if (l -> prior > r -> prior) {
                l -> r = merge(l -> r, r);
                return l;
            }
            else {
                r -> l = merge(l, r -> l);
                return r;
            }
        }
};




int main() {

    char c;
    cin >> c;

    while (c != 'E') {

        cin >> c;
    }
}
