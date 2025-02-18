#include "UnionFind.hh"
#include <cstdlib>
#include <iostream>
using namespace std;
#define min(a,b) (((a)<(b))?(a):(b))


UnionFind::UnionFind(unsigned int n, UnionStrategy s, PathStrategy p) {
    P = (int*) malloc(n * sizeof(int));

    weighted = s != UnionStrategy::QU;
    if (not weighted) for (unsigned int i = 0; i < n; ++i) P[i] = i;
    else for (unsigned int i = 0; i < n; ++i) P[i] = -1;

    strat = s;
    path = p;
    numBlocks = n;
    size = n;
}

UnionFind::~UnionFind() {
    free(P);
}

unsigned int UnionFind::find(unsigned int i) {

    switch(path) {
        case PathStrategy::FC:
            return pathFC(i);
        case PathStrategy::PS:
            return pathPS(i);
        case PathStrategy::PH:
            return pathPH(i);
        default:
            while (weighted ? P[i] > 0 : P[i] != i) i = P[i];
            return i;
    }
}

unsigned int UnionFind::pathFC(unsigned int i) {

    if (weighted ? P[i] < 0 : P[i] == i) return i;

    else {
        P[i] = pathFC(P[i]);
        return P[i];
    }
}

unsigned int UnionFind::pathPS(unsigned int i) {

    if (weighted ? P[i] < 0 : P[i] == i) return i;

    unsigned int i1 = i;
    unsigned int i2 = P[i1];

    while (weighted ? P[i2] > 0 : P[i2] != i2) {
        P[i1] = P[i2];
        i1 = i2;
        i2 = P[i2];
    }

    return i2;
}

unsigned int UnionFind::pathPH(unsigned int i) {

    if (weighted ? P[i] < 0 : P[i] == i) return i;

    unsigned int i1 = i;
    unsigned int i2 = P[i1];
    bool setParent = true;

    while (weighted ? P[i2] > 0 : P[i2] != i2) {

        if (setParent) P[i1] = P[i2];
        setParent = not setParent;
        i1 = i2;
        i2 = P[i2];
    }

    return i2;
}

unsigned int UnionFind::num_blocks() const {
    return numBlocks;
}

void UnionFind::merge(unsigned int ri, unsigned int rj) {

    switch(strat) {
        case UnionStrategy::QU:
            mergeQU(ri, rj);
            break;
        case UnionStrategy::UW:
            mergeUW(ri, rj);
            break;
        case UnionStrategy::UR:
            mergeUR(ri, rj);
            break;
    }
}



void UnionFind::mergeQU(unsigned int i, unsigned int j) {

    unsigned int ri = find(i);
    unsigned int rj = find(j);

    if (ri != rj) {
        P[ri] = rj;
        --numBlocks;
        for (unsigned int k = 0; k < size; ++k) cout << P[k] << " ";
        cout << endl;
    }

}

void UnionFind::mergeUW(unsigned int i, unsigned int j) {

    unsigned int ri = find(i);
    unsigned int rj = find(j);

    if (ri != rj) {
        //Negative numbers, p[ri] is smaller than p[rj]
        if (P[ri] >= P[rj]) {
            P[rj] += P[ri];
            P[ri] = rj;
        }

        else {
            P[ri] += P[rj];
            P[rj] = ri;
        }
         --numBlocks;
         for (unsigned int k = 0; k < size; ++k) cout << P[k] << " ";
         cout << endl;

    }
}

void UnionFind::mergeUR(unsigned int i, unsigned int j) {

    unsigned int ri = find(i);
    unsigned int rj = find(j);

    if (ri != rj) {
        //Recall that P[ri] and P[rj] are negative numbers!!!!
        if (P[ri] >= P[rj]) {
            P[rj] = min(P[rj], P[ri] - 1);
            P[ri] = rj;
        }

        else {
            P[ri] = min(P[ri], P[rj] - 1);
            P[rj] = ri;
        }
        --numBlocks;
         for (unsigned int k = 0; k < size; ++k) cout << P[k] << " ";
         cout << endl;
    }
}
