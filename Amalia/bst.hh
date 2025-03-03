
class BST {

    public:
        BST();

        ~BST();

        void insert(float x);

        unsigned int find(float x);

        void print();

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
};
