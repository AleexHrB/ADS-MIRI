class UnionFind {

    public:

        //Quick Union, Union by Weight, Union by Rank
        enum UnionStrategy {
            QU,
            UW,
            UR
        };

        //No Compression, Full Compression, Path Splitting, Path Halving
        enum PathStrategy {
            NC,
            FC,
            PS,
            PH
        };

        //Creates a UnionFind data structure of size n with 
        //strategies provided
        UnionFind(unsigned int n, UnionStrategy s, PathStrategy p);

        ~UnionFind();

        //Given an element $0 <= i < n$ return the 
        //representative of the class that it belongs
        unsigned int find(unsigned int i);

        //Given two elements $0 <= i < n$ and $0 <= i < j$
        //merge the classes from which i,j belongs.
        void merge(unsigned int i, unsigned int j);

        unsigned int num_blocks() const;

        unsigned int getTPL() const;

        unsigned int getTPU() const;

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

        //Counter to keep track of how many pointers
        //have been switched during find operations.
        unsigned int tpu;

        //Perform different union and find operations depending
        //on the strategy
        void mergeQU(unsigned int i, unsigned int j);
        void mergeUW(unsigned int i, unsigned int j);
        void mergeUR(unsigned int i, unsigned int j);

        inline unsigned int parent(unsigned int i);

        unsigned int pathFC(unsigned int i);
        unsigned int pathPS(unsigned int i);
        unsigned int pathPH(unsigned int i);
};
