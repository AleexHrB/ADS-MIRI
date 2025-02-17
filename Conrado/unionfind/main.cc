#include <algorithm>
#include <iostream>
#include "UnionFind.hh"
using namespace std;


struct myPair {
    unsigned int first;
    unsigned int second;
};

int main(int argc, char** argv) {

    unsigned int size = atoi(argv[1]);
    unsigned int m = size*(size - 1) / 2;

    myPair* pairs = (myPair*) malloc(m * sizeof(myPair));

    unsigned int index = 0;
    for (unsigned int i = 0; i < size; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            pairs[index].first = i;
            pairs[index].second = j;
            ++index;
        }
    }

    srand(time(NULL));
    random_shuffle(&pairs[0], &pairs[m]);

    UnionFind uf(size, UnionFind::UR, UnionFind::PH);

    index = 0;
    while (uf.num_blocks() != 1 and index < m) {
        uf.merge(pairs[index].first, pairs[index].second);
        ++index;
    }

    free(pairs);

}
