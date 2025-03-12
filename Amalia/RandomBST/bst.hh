
class BST {

    public:
        BST();

        //Free memory
        ~BST();

        //Inserts key x to the BST
        void insert(float x);

        //Return the number of nodes that we traversed to find key x. It does not
        //give any special value if key x does not exist.
        unsigned int find(float x);

        //Calculate and return the IPL of the BST
        unsigned int ipl();

        //Erase key x from our BST.
        void erase(float x);

    private:
        struct node {
            node* l = nullptr;
            node* r = nullptr;
            float x;
        };

        node* root;

        //Functions to recursively do our operations.
        node* insert(float x, node* n);
        unsigned int find(float x, node* n);
        void freeMemory(node* n);
        node* erase(node* n, float x);
        node* eraseSuccessor(node* n, float& x);
};
