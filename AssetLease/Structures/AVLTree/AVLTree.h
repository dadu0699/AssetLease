#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "AVLTreeNode.h"

using namespace std;

class AVLTree
{
private:
    AVLTreeNode *root;
    int indexNode;

    bool isEmpty();
    int max(int a, int b);
    int updateHeight(AVLTreeNode *avlTreeNode);
    int getBalanceFactor(AVLTreeNode *avlTreeNode);
    AVLTreeNode *nodeWithMinimumValue(AVLTreeNode *avlTreeNode);
    AVLTreeNode *leftRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *rightRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *rightLeftRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *leftRightRotation(AVLTreeNode *avlTreeNode);
    AVLTreeNode *insert(AVLTreeNode *newNode, AVLTreeNode *avlTreeNode);
    AVLTreeNode *deleteNode(AVLTreeNode *avlTreeNode, string identifier);
    AVLTreeNode *search(string identifier, AVLTreeNode *avlTreeNode);
    void inOrder(AVLTreeNode *root);
    void inOrderM(AVLTreeNode *root);
    string report(AVLTreeNode *root);
    string generalReport(AVLTreeNode *root);
    string reportLeftNode(AVLTreeNode *root, int indexParentNode);
    string reportRightNode(AVLTreeNode *root, int indexParentNode);

public:
    AVLTree();
    ~AVLTree();

    void insert(Asset *asset);
    void deleteNode(string identifier);
    AVLTreeNode *search(string identifier);
    void inOrder();
    void inOrderM();
    void report(string user, string department, string corporation);
    string generalReport(string user, string department, string corporation);
};

#endif // AVLTREE_H
