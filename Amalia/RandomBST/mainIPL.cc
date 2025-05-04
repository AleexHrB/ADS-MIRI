#include <iostream>
#include <random>
#include "bst.hh"
using namespace std;

int main(int argc, char** argv) {

    unsigned int n = atoi(argv[1]);
    unsigned int seed = atoi(argv[2]);

    BST t;

    mt19937 generator(seed);
    uniform_real_distribution<float> distribution(0.0, 1.0);
    for (unsigned int i = 0; i < n; ++i) t.insert(distribution(generator));
    
    cout << n << "," << t.ipl() << endl;
}
