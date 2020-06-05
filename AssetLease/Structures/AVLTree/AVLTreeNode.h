#ifndef AVLTREENODE_H
#define AVLTREENODE_H

#include "../../Models/Asset.h"

class AVLTreeNode
{
private:
    Asset *asset;
    int height;
    AVLTreeNode *leftNode;
    AVLTreeNode *rightNode;

public:
    AVLTreeNode(Asset *asset);
    ~AVLTreeNode();

    Asset *getAsset() const;

    int getHeight();
    void setHeight(int height);

    AVLTreeNode *getLeftNode() const;
    void setLeftNode(AVLTreeNode *leftNode);

    AVLTreeNode *getRightNode() const;
    void setRightNode(AVLTreeNode *rightNode);
};

#endif // AVLTREENODE_H
