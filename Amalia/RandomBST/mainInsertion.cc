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
    

    unsigned int q = 2*n;
    unsigned int tpl = 0;
    for (unsigned int i = 0; i < q; ++i) tpl += t.find(distribution(generator));

    cout << n << "," << float(tpl) / q << endl;
}

