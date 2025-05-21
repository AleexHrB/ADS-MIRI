#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define parent(i) (P[i] < 0 ? (i) : P[i])
class UnionFind {

    public:

        //Quick Union, Union by Weight, Union by Rank
        enum UnionStrategy {
            UW
        };

        //No Compression, Full Compression, Path Splitting, Path Halving
        enum PathStrategy {
            FC,
        };

        //Creates a UnionFind data structure of size n with 
        //strategies provided
        UnionFind(unsigned int n, UnionStrategy s, PathStrategy p) {
            P = (int*) malloc(n * sizeof(int));
            for (unsigned int i = 0; i < n; ++i) P[i] = -1;

            strat = s;
            path = p;
            numBlocks = n;
            size = n;
        };

        ~UnionFind() {
            free(P);
        };

        //Given an element $0 <= i < n$ return the 
        //representative of the class that it belongs
        unsigned int find(unsigned int i) {
            return pathFC(i);
        };

        //Given two elements $0 <= i < n$ and $0 <= i < j$
        //merge the classes from which i,j belongs.
        void merge(unsigned int i, unsigned int j) {
            unsigned int ri = find(i);
            unsigned int rj = find(j);
            if (ri == rj) return;
            mergeUW(ri, rj);
        }


    private:
        //Array to represent Union-Find
        int* P;

        unsigned int numBlocks;
        unsigned int size;

        //weighted is false if the representative
        //is represented with its number. True otherwise
        bool weighted;

        UnionStrategy strat;
        PathStrategy path;

        void mergeUW(unsigned int ri, unsigned int rj) {
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
        unsigned int pathFC(unsigned int i) {
            if (parent(i) == parent(parent(i))) return parent(i);
            else {
                P[i] = pathFC(P[i]);
                return P[i];
            }
        }
};

struct edge {
    unsigned int u;
    unsigned int v;
    unsigned int w;
};



int main() {
    unsigned int n;
    unsigned int m;

    while (cin >> n >> m) {
        UnionFind uf(n,UnionFind::UW, UnionFind::FC);
        edge edges[m];
        unsigned int total = 0;
        for (unsigned int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            total += edges[i].w;
        }

        sort(edges, edges + m, [](const edge& a, const edge& b) {
                return a.w < b.w;
                });
        for (unsigned int i = 0; i < m; ++i) {
            if (uf.find(edges[i].u) != uf.find(edges[i].v)) {
                uf.merge(edges[i].u, edges[i].v);
                total -= edges[i].w;
            }
        }

        cout << total << endl;
    }
}
