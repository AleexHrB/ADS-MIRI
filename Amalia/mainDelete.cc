#include <iostream>
#include "bst.hh"
using namespace std;

int main(int argc, char** argv) {

    unsigned int n = atoi(argv[1]);
    unsigned int seed = atoi(argv[2]);

    float v[n*n];

    BST t;

    unsigned int lastElem = n - 1;

    srand(seed);
    for (unsigned int i = 0; i < n; ++i) {
        v[i] = ((double)rand()) / RAND_MAX;
        t.insert(v[i]);
    }

    unsigned int erasedElems = 0;
    unsigned int size = n;

    for (unsigned int i = 0; i < n*n; ++i) {

        if (rand() % 2 == 0) {
            ++lastElem;
            v[lastElem] = ((double)rand()) / RAND_MAX;
            t.insert(v[lastElem]);
            ++size;
        }

        else {
            unsigned int cand = rand() % (lastElem - erasedElems + 1) + erasedElems;
            float aux = v[cand];
            v[cand] = v[erasedElems];
            v[erasedElems] = aux;
            t.erase(aux);
            ++erasedElems;
            --size;
        }
    }

    
    cout << size << "," << t.ipl() << endl;
}
