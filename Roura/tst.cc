#include <iostream>
#include <algorithm>
using namespace std;

class TST {

    public:

        void print() {
            print(root);
        }

        void reset() {
            root = reset(root);
        }

        void insert(const string& s) {
            bool b;
            root = insert(root, s,0,b);
        }

        void erase(const string& s) {
            bool b;
            root = erase(root, s,0,b);
        }

        unsigned int count(const string& s) {
            return count(root,s,0);
        }

    private:
        struct node {
            node* l = nullptr;
            node* r = nullptr;
            node* m = nullptr;
            char c;
            bool valid = true;
            unsigned int n = 0;
        };

        node* root = nullptr;

        unsigned int count(node* p, const string& s, unsigned int i) {
            if (p == nullptr) return 0;
            if (i == s.length()) return p -> n;
            if (p -> c < s[i]) return count(p -> r, s, i);
            else if (p -> c > s[i]) return count(p -> l, s, i);
            else return count(p -> m, s, i+1);
        }

        node* insert(node* p, const string& s, unsigned int i, bool& alreadyThere) {

            if (p == nullptr) {
                p = new node;
                p -> c = i == s.length() ? '!' : s[i];
                if (i < s.length()) {
                    p -> m = insert(p -> m,s,i+1,alreadyThere);
                    p -> m -> n = 1;
                }
                alreadyThere = false;
                return p;
            }

            if (i == s.length()) {
                alreadyThere = p -> valid and p -> c == '!';
                p -> valid = true;
                return p;
            }

            if (p -> c < s[i]) p -> r = insert(p -> r, s, i,alreadyThere);
            else if (p -> c > s[i]) p -> l = insert(p -> l, s, i,alreadyThere);
            else {
                p -> m = insert(p -> m, s, i+1,alreadyThere);
                if (not alreadyThere and p -> m != nullptr) ++p->m->n;
            }

            return p;
        }

        node* erase(node* p, const string& s, unsigned int i, bool& alreadyThere) {
            if (p == nullptr) {
                alreadyThere = false;
                return nullptr;
            }
            if (i == s.length()) {
                alreadyThere = p -> valid and p -> c == '!';
                p -> valid = false;
                return p;
            }
            if (p -> c < s[i]) p -> r = erase(p -> r, s, i,alreadyThere);
            else if (p -> c > s[i]) p -> l = erase(p -> l, s, i,alreadyThere);
            else {
                p -> m = erase(p -> m, s, i+1,alreadyThere);
                if (alreadyThere and p -> m != nullptr) --p->m->n; 
            }

            return p;
        }

        node* reset(node* p) {
            if (p == nullptr) return nullptr;
            p -> m = reset(p -> m);
            p -> l = reset(p -> l);
            p -> r = reset(p -> r);
            delete p;
            return nullptr;
        }

        void print(node* p) {
            if (p == nullptr) cout << "Null" << endl;
            else {
                cout << p -> c << endl;
                print(p -> m);
                print(p -> l);
                print(p -> r);
            }
        }
};





int main() {
    TST t;
    char c;

    while (cin >> c) {
        string s;
        if (c != 'R') {
            cin >> s;
            reverse(s.begin(), s.end());
        }

        else {
            //t.print();
            t.reset();
            cout << "---" << endl;
        }

        if (c == 'E') t.erase(s);
        if (c == 'I') t.insert(s);
        if (c == 'C') cout << t.count(s) << endl;
    }
}
