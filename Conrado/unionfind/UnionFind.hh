class UnionFind {

    public:

        enum UnionStrategy {
            QU,
            UW,
            UR
        };

        enum PathStrategy {
            NC,
            FC,
            PS,
            PH
        };

        UnionFind(unsigned int n, UnionStrategy s, PathStrategy p);

        ~UnionFind();

        unsigned int find(unsigned int i);

        void merge(unsigned int ri, unsigned int rj);

        unsigned int num_blocks() const;

    private:
        int* P;
        unsigned int numBlocks;
        unsigned int size;
        bool weighted;
        UnionStrategy strat;
        PathStrategy path;

        void mergeQU(unsigned int i, unsigned int j);
        void mergeUW(unsigned int i, unsigned int j);
        void mergeUR(unsigned int i, unsigned int j);

        unsigned int pathFC(unsigned int i);
        unsigned int pathPS(unsigned int i);
        unsigned int pathPH(unsigned int i);
};
