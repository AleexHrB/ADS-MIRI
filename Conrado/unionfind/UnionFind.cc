#include "UnionFind.hh"
#include <cstdlib>
#include <cstdio>
using namespace std;
#define min(a,b) (((a)<(b))?(a):(b))
#define parent(i) (P[i] < 0 ? (i) : P[i])


UnionFind::UnionFind(unsigned int n, UnionStrategy s, PathStrategy p) {
    P = (int*) malloc(n * sizeof(int));

    if (s == UnionStrategy::QU) for (unsigned int i = 0; i < n; ++i) P[i] = i;
    else for (unsigned int i = 0; i < n; ++i) P[i] = -1;

    strat = s;
    path = p;
    numBlocks = n;
    size = n;
    tpu = 0;
}

UnionFind::~UnionFind() {
    free(P);
}

unsigned int UnionFind::getTPL() const {

    unsigned int tpl = 0;

    for (unsigned int i = 0; i < size; ++i) {
        unsigned int j = i;

        while (parent(j) != j) {
            j = P[j];
            ++tpl;
        }

    }

    return tpl;
}

unsigned int UnionFind::getTPU() const {
    return tpu;
}

unsigned int UnionFind::find(unsigned int i) {

    switch(path) {
        case PathStrategy::FC:
            return pathFC(i);
        case PathStrategy::PS:
            return pathPS(i);
        case PathStrategy::PH:
            return pathPH(i);
        case PathStrategy::TOR:
            return pathR(i);
        default:
            while (parent(i) != i) i = P[i];
            return i;
    }
}

unsigned int UnionFind::pathR(unsigned int i) {

    unsigned int finalNode = i;
    i = parent(i);

    while (parent(i) != parent(parent(i))) {
        unsigned int aux = P[i];
        P[i] = finalNode;
        i = aux;
#ifndef TIME
        ++tpu;
#endif
    }

    if (parent(finalNode) != parent(i)) {
        P[finalNode] = parent(i);
        P[i] = finalNode;
#ifndef TIME
        tpu += 2;
#endif
    }
    return parent(finalNode);
}

unsigned int UnionFind::pathFC(unsigned int i) {

    if (parent(i) == parent(parent(i))) return parent(i);

    else {
        P[i] = pathFC(P[i]);
#ifndef TIME
        ++tpu;
#endif
        return P[i];
    }
}

unsigned int UnionFind::pathPS(unsigned int i) {

    while (parent(i) != parent(parent(i))) {
        unsigned int aux = P[i];
        P[i] = P[P[i]];
        i = aux;
#ifndef TIME
        ++tpu;
#endif
    }

    return parent(i);
}

unsigned int UnionFind::pathPH(unsigned int i) {

    while (parent(i) != parent(parent(i))) {
        P[i] = P[P[i]];
        i = P[i];
#ifndef TIME
        ++tpu;
#endif
    }

    return parent(i);
}

unsigned int UnionFind::num_blocks() const {
    return numBlocks;
}

void UnionFind::merge(unsigned int i, unsigned int j) {


    unsigned int ri = find(i);
    unsigned int rj = find(j);
    if (ri == rj) return;
    --numBlocks;
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
        default:
            break;
    }
}



void UnionFind::mergeQU(unsigned int ri, unsigned int rj) {
    P[ri] = rj;
}

void UnionFind::mergeUW(unsigned int ri, unsigned int rj) {

    //Negative numbers, p[ri] is smaller than p[rj]
    if (P[ri] >= P[rj]) {
        P[rj] += P[ri];
        P[ri] = rj;
    }

    else {
        P[ri] += P[rj];
        P[rj] = ri;
    }
}

void UnionFind::mergeUR(unsigned int ri, unsigned int rj) {

    //Recall that P[ri] and P[rj] are negative numbers!!!!
    if (P[ri] >= P[rj]) {
        P[rj] = min(P[rj], P[ri] - 1);
        P[ri] = rj;
    }

    else {
        P[ri] = min(P[ri], P[rj] - 1);
        P[rj] = ri;
    }
}
