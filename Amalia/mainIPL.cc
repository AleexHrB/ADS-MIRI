#include <iostream>
#include "bst.hh"
using namespace std;

int main(int argc, char** argv) {

    unsigned int n = atoi(argv[1]);
    unsigned int seed = atoi(argv[2]);

    BST t;

    srand(seed);
    for (unsigned int i = 0; i < n; ++i) t.insert(((double)rand()) / RAND_MAX);
    
    cout << n << "," << t.ipl() << endl;
}
