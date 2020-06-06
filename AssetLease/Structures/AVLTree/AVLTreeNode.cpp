#include "AVLTreeNode.h"

AVLTreeNode::AVLTreeNode(Asset *asset)
{
	this->asset = asset;
	this->height = 1;
	leftNode = nullptr;
	rightNode = nullptr;
}

AVLTreeNode::~AVLTreeNode()
{
}

Asset *AVLTreeNode::getAsset() const
{
	return asset;
}

void AVLTreeNode::setAsset(Asset *asset)
{
	this->asset = asset;
}

int AVLTreeNode::getHeight()
{
	return height;
}

void AVLTreeNode::setHeight(int height)
{
	this->height = height;
}

AVLTreeNode *AVLTreeNode::getLeftNode() const
{
	return leftNode;
}

void AVLTreeNode::setLeftNode(AVLTreeNode *leftNode)
{
	this->leftNode = leftNode;
}

AVLTreeNode *AVLTreeNode::getRightNode() const
{
	return rightNode;
}

void AVLTreeNode::setRightNode(AVLTreeNode *rightNode)
{
	this->rightNode = rightNode;
}
