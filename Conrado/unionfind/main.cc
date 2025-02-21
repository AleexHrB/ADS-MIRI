#include <algorithm>
#include <iostream>
#include "UnionFind.hh"
using namespace std;


int main(int argc, char** argv) {

    unsigned int size = atoi(argv[1]);
    unsigned int us = atoi(argv[2]);
    unsigned int ps = atoi(argv[3]);

    UnionFind::UnionStrategy eus;
    UnionFind::PathStrategy eps;

    switch(us) {
        case 0:
            eus = UnionFind::QU;
            break;
        case 1:
            eus = UnionFind::UW;
            break;
        case 2:
            eus = UnionFind::UR;
            break;
        default:
            cout << "Please provide a valid Union Strategy (number from 0-2)" << endl;
            return -1;
    }

    switch(ps) {
        case 0:
            eps = UnionFind::NC;
            break;
        case 1:
            eps = UnionFind::FC;
            break;
        case 2:
            eps = UnionFind::PS;
            break;
        case 3:
            eps = UnionFind::PH;
            break;
        default:
            cout << "Please provide a valid Path Strategy (number from 0-3)" << endl;
            return -1;
    }

    unsigned int delta = 250;
    unsigned int count = 0;

    UnionFind uf(size, eus, eps);

    printf("tpl,tpu\n");

    while (uf.num_blocks() != 1) {

        if (count == delta) {
            unsigned int tpl = uf.getTPL();
            unsigned int tpu = uf.getTPU();
            printf("%d,%d\n", tpl, tpu);
            count = 0;
        }

        unsigned int i,j;
        cin >> i >> j;
        uf.merge(i,j);
        ++count;
    }
}
