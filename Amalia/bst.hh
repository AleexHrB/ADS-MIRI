
class BST {

    public:
        BST();

        ~BST();

        void insert(float x);

        unsigned int find(float x);

        void print();

        unsigned int ipl();

        void erase(float x);

    private:
        struct node {
            node* l = nullptr;
            node* r = nullptr;
            float x;
        };

        node* root;

        node* insert(float x, node* n);
        unsigned int find(float x, node* n);
        void print(node* n);
        void freeMemory(node* n);
        node* erase(node* n, float x);
        node* eraseSuccessor(node* n, float& x);
};
