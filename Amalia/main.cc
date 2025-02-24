#include <iostream>
#include <algorithm>
#include "bst.hh"
using namespace std;








int main(int argc, char** argv) {

    unsigned int n = atoi(argv[1]);
    unsigned int keys[n];

    BST t;

    for (unsigned int i = 0; i < n; ++i) keys[i] = i;

    srand(time(NULL));
    random_shuffle(&keys[0], &keys[n]);
    for (unsigned int i = 0; i < n; ++i) cout << keys[i] << " ";
    cout << endl;
    for (unsigned int i = 0; i < n; ++i) t.insert(keys[i]);

    t.print();
}
