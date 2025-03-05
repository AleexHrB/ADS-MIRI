#include <iostream>
#include "bst.hh"
using namespace std;

int main(int argc, char** argv) {

    unsigned int n = atoi(argv[1]);
    unsigned int seed = atoi(argv[2]);

    float v[n];

    BST t;

    unsigned int size = n;

    srand(seed);
    for (unsigned int i = 0; i < n; ++i) v[i] = ((double)rand()) / RAND_MAX;

    unsigned int prob = 10;

    t.insert(v[0]);
    for (unsigned int i = 1; i < n; ++i) {
        t.insert(v[i]);
        if (rand() % prob == 0) {
            t.erase(v[rand() % i]);
            --size;
        }
    }
    
    cout << size << "," << t.ipl() << endl;
}
