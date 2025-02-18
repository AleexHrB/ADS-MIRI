#include <algorithm>
#include <iostream>
#include "UnionFind.hh"
using namespace std;


int main(int argc, char** argv) {

    unsigned int size;
    cin >> size;

    unsigned int UR,PH;
    cin >> UR >> PH;

    unsigned int delta = 250;
    unsigned int count = 0;

    UnionFind uf(size, UnionFind::UnionStrategy(UR), UnionFind::PathStrategy(PH));

    while (uf.num_blocks() != 1) {

        if (count == delta) {
            unsigned int tpl = uf.getTPL();
            unsigned int tpu = uf.getTPU();
            uf.resetMetric();
            printf("TPL = %d, TPU = %d \n", tpl, tpu);
            count = 0;
        }

        unsigned int i,j;
        cin >> i >> j;
        uf.merge(i,j);
        ++count;
    }
}
