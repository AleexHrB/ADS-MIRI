
class BST {

    public:
        BST();

        void insert(unsigned int x);

        void erase(unsigned int x);

        bool find(unsigned int x);

        void print();

    private:
        struct node {
            node* l = nullptr;
            node* r = nullptr;
            unsigned int x;
        };

        node* root;

        node* insert(unsigned int x, node* n);
        node* erase(unsigned int x, node* n);
        bool find(unsigned int x, node* n);
        void print(node* n);
};
