#include <iostream>
#include <set>
#include <cstdlib>
#include "UnionFind.hh"
using namespace std;


int main(int argc, char**argv) {

    unsigned int n = atoi(argv[1]);
    unsigned int seed = atoi(argv[2]);

    UnionFind uf(n, UnionFind::UW, UnionFind::PS);
    srand(seed);
    
    set<pair<unsigned int, unsigned int>> s;

    while (uf.num_blocks() != 1) {
        pair<unsigned int, unsigned int> p = {0,0};

        while (p.first == p.second or s.find(p) != s.end()) {
            p.first = rand() % n;
            p.second = rand()% n;

            if (p.first > p.second) {
                unsigned int aux = p.first;
                p.first = p.second;
                p.second = aux;
            }
        }

        s.insert(p);

        cout << p.first << " " <<  p.second << endl;
        uf.merge(p.first, p.second);
    }

    //uf.printUF();
    //cout << uf.num_blocks() << endl;

}
