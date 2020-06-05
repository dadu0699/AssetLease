#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "AVLTreeNode.h"

using namespace std;

class AVLTree
{
private:
    AVLTreeNode* root;
    int indexNode;

    bool isEmpty();
    int max(int a, int b);
    int updateHeight(AVLTreeNode* avlTreeNode);
    int getBalanceFactor(AVLTreeNode* avlTreeNode);
    AVLTreeNode *nodeWithMinimumValue(AVLTreeNode* avlTreeNode);
    AVLTreeNode *leftRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *rightRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *rightLeftRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *leftRightRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *insert(AVLTreeNode *newNode, AVLTreeNode *avlTreeNode);
    string report(AVLTreeNode *root);

public:
    AVLTree();
    ~AVLTree();

    AVLTreeNode *search(string identifier, AVLTreeNode *avlTreeNode);
    void insert(Asset *asset);
    void report();
};

#endif // AVLTREE_H
