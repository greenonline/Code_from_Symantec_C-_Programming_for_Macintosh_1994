/* Chapter 4 - BinaryTree */
/* Main.cp */

struct BinaryTree { 
    int value;

    BinaryTree *left; 
    BinaryTree *right;

    BinaryTree(int v) {value v; left = right = NULL;}
};

Boolean CheckBinaryTree(BinaryTree *aTree)
{
    if (aTree == NULL) 
        return true;

    if (aTree->left != NULL) {
        if (aTree->left->value > aTree->value)
            return false;
        if (!CheckBinaryTree(aTree->left))
            return false;
    }
    if (aTree->right != NULL) {
        if (aTree->value > aTree->right->value) return false;
        if (!CheckBinaryTree(aTree->right)) return false;
    }
    return TRUE;
}

BinaryTree *NewNode(int value) {
    return new BinaryTree(value);
}

main() {
    /* construct binary tree by hand.
       Should really write a function to do it */

    BinaryTree *root = NULL;
    BinaryTree *node;
    node = NewNode(5); 
    root = node;

    node= NewNode(3); 
    root->left = node;

    node= NewNode(4); 
    root->left->left = node;

    node= NewNode(8); 
    root->right = node;

    return 0;
}