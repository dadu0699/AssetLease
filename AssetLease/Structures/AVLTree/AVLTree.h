#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLTreeNode.h"

class AVLTree
{
private:
    AVLTreeNode *root;

    bool isEmpty();
    int max(int a, int b);

public:
    AVLTree();
    ~AVLTree();

    AVLTreeNode *search(string identifier, AVLTreeNode *avlTreeNode);
    int getBalanceFactor(AVLTreeNode *avlTreeNode);
    AVLTreeNode *leftRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *rightRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *rightLeftRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *leftRightRotation(AVLTreeNode *avlTreeNode);
};

#endif // AVLTREE_H
