using namespace std;
template <typename T>
class BinaryTreeNode
{

    /* data */
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
