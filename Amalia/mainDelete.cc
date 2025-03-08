#include <iostream>
#include <random>
#include "bst.hh"
using namespace std;

int main(int argc, char** argv) {

    unsigned int n = atoi(argv[1]);
    unsigned int seed = atoi(argv[2]);

    float *v = (float *) malloc(n*n*sizeof(float));

    BST t;
    unsigned int lastElem = n - 1;

    mt19937 generator(seed);
    uniform_real_distribution<float> distribution(0.0, 1.0);
    for (unsigned int i = 0; i < n; ++i) {
        v[i] = distribution(generator);
        t.insert(v[i]);
    }

    unsigned int erasedElems = 0;
    srand(seed);
    bool ins = true;
    for (unsigned int i = 0; i < n*n; ++i) {

        if (ins) {
            ++lastElem;
            v[lastElem] = distribution(generator);
            t.insert(v[lastElem]);
        }

        else {
            unsigned int cand = rand() % (lastElem - erasedElems + 1) + erasedElems;
            float aux = v[cand];
            v[cand] = v[erasedElems];
            v[erasedElems] = aux;
            t.erase(aux);
            ++erasedElems;
        }

        ins = !ins;

    }

    
    cout << n << "," << t.ipl() << endl;
    free(v);
}
