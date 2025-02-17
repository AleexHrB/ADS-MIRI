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

    unsigned int ri = i;
    while (weighted ? P[i] > 0 : P[i] != i) i = P[i];

    unsigned int aux = ri;
    ri = i;
    i = aux;

    switch(path) {
        case PathStrategy::FC:
            pathFC(i, ri);
            break;
        case PathStrategy::PS:
            pathPS(i);
            break;
        case PathStrategy::PH:
            pathPH(i);
            break;
        default:
            break;
    }

    return ri;
}

void UnionFind::pathFC(unsigned int i, unsigned int ri) {

    while (weighted ? P[i] > 0 : P[i] != i) {
        int aux = i;
        i = P[i];
        P[aux] = ri;
    }
}

void UnionFind::pathPS(unsigned int i) {

    int setParent[2] = {-1,-1};
    unsigned int index = 0;

    while (weighted ? P[i] > 0 : P[i] != i) {

        if (setParent[index] != -1) {
            P[setParent[index]] = i;
        }

        setParent[index] = i;
        ++index;
        index = index & 0x01;

        i = P[i];
    }
}

void UnionFind::pathPH(unsigned int i) {


    bool setParent = false;
    unsigned int childIndex = i;

    if (weighted ? P[i] > 0 : P[i] != i) i = P[i];

    while (weighted ? P[i] > 0 : P[i] != i) {

        if (setParent) {
            P[childIndex] = i;
            childIndex = i;
        }

        setParent = not setParent;
        i = P[i];
    }
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
