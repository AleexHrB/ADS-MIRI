#include <iostream>
#include <algorithm>
using namespace std;

class Trie {
    public:
        void reset() {
            reset(root);
            root = nullptr;
        }

        void insert(string& s) {
            s.push_back('!');
            bool b;
            root = insert(s,0,root,b);
        }

        void erase(string& s) {
            s.push_back('!');
            bool b;
            root = erase(s,0,root,b);
        }

        unsigned int count(string& s) {
            return count(s,0,root);
        }

    private:
        struct node {
            node* m = nullptr;
            node* l = nullptr;
            node* r = nullptr;
            char c;
            unsigned int n = 1;
            bool valid = true;
        };

        node* root = nullptr;

        unsigned int count(const string& s, unsigned int i, node* p) {
            if (p == nullptr) return 0;
            if (i >= s.length()) return 0;
            if (i+1 == s.length() and p -> c == s[i]) return p -> n;
            if (p -> c < s[i]) return count(s,i,p->r);
            else if (p -> c > s[i]) return count(s,i,p->l);
            else return count(s,i+1,p->m);
        }

        node* insert(const string& s, unsigned int i, node* p, bool& exists) {
            if (p == nullptr) {
                p = new node;
                p -> c = s[i];
                if (s[i] != '!') p -> m = insert(s,i+1,p->m, exists);
                exists = false;
                return p;
            }

            if (i+1 == s.length() and p -> c == '!') {
                exists = p -> valid;
                p -> valid = true;
                return p;
            }

            if (p -> c < s[i]) p -> r = insert(s,i,p->r,exists);
            else if (p -> c > s[i]) p -> l = insert(s,i,p->l,exists);
            else {
                p -> m = insert(s,i+1,p->m,exists);
                if (not exists) ++p->n;
            }

            return p;
        }

        node* erase(const string& s, unsigned int i, node* p, bool& exists) {
            if (p == nullptr) {
                exists = false;
                return p;
            }

            if (i+1 == s.length() and p -> c == '!') {
                exists = p -> valid;
                p -> valid = false;
                if (p -> m == nullptr and p -> l == nullptr and p -> r == nullptr) {
                    delete p;
                    return nullptr;
                }
                return p;
            }

            if (p -> c < s[i]) p -> r = erase(s,i,p->r,exists);
            else if (p -> c > s[i]) p -> l = erase(s,i,p->l,exists);
            else {
                p -> m = erase(s,i+1,p->m,exists);
                if (p -> m == nullptr and p -> l == nullptr and p -> r == nullptr) {
                    delete p;
                    return nullptr;
                }
                if (exists) --p->n;
            }

            return p;
        }

        void reset(node* p) {
            if (p != nullptr) {
                reset(p -> m);
                reset(p -> l);
                reset(p -> r);
                delete p;
            }
        }
};



int main() {
    char c;
    Trie t;
    while (cin >> c) {
        if (c == 'R') {
            t.reset();
            cout << "---" << endl;
        }
        else if (c == 'I') {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            t.insert(s);
        }

        else if (c == 'E') {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            t.erase(s);
        }
        
        else if (c == 'C') {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            cout << t.count(s) << endl;
        }
    }
}
