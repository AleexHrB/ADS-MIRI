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

        void merge(unsigned int i, unsigned int j);

        unsigned int num_blocks() const;

        unsigned int getTPL() const;

        unsigned int getTPU() const;

    private:
        int* P;
        unsigned int numBlocks;
        unsigned int size;
        bool weighted;
        UnionStrategy strat;
        PathStrategy path;

        unsigned int tpu;

        void mergeQU(unsigned int i, unsigned int j);
        void mergeUW(unsigned int i, unsigned int j);
        void mergeUR(unsigned int i, unsigned int j);

        inline unsigned int parent(unsigned int i);

        unsigned int pathFC(unsigned int i);
        unsigned int pathPS(unsigned int i);
        unsigned int pathPH(unsigned int i);
};
