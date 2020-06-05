#include "AVLTree.h"

AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
}

bool AVLTree::isEmpty()
{
	return root == nullptr;
}

int AVLTree::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

AVLTreeNode *AVLTree::search(string identifier, AVLTreeNode *avlTreeNode)
{
	if (isEmpty())
	{
		return nullptr;
	}
	else if (avlTreeNode->getAsset()->getIdentifier() == identifier)
	{
		return avlTreeNode;
	}
	else if (avlTreeNode->getAsset()->getIdentifier() < identifier)
	{
		return search(identifier, avlTreeNode->getRightNode());
	}
	else
	{
		return search(identifier, avlTreeNode->getLeftNode());
	}
}

int AVLTree::getBalanceFactor(AVLTreeNode *avlTreeNode)
{
	if (avlTreeNode == nullptr)
	{
		return -1;
	}
	return avlTreeNode->getHeight();
}

AVLTreeNode *AVLTree::leftRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode = avlTreeNode->getLeftNode();
	avlTreeNode->setLeftNode(auxiliaryNode->getRightNode());
	auxiliaryNode->setRightNode(avlTreeNode);
	avlTreeNode->setHeight(max(getBalanceFactor(avlTreeNode->getLeftNode()), getBalanceFactor(avlTreeNode->getRightNode())) + 1);
	auxiliaryNode->setHeight(max(getBalanceFactor(auxiliaryNode->getLeftNode()), getBalanceFactor(auxiliaryNode->getRightNode())) + 1);
	return auxiliaryNode;
}

AVLTreeNode* AVLTree::rightRotation(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode* auxiliaryNode = avlTreeNode->getRightNode();
	avlTreeNode->setRightNode(auxiliaryNode->getLeftNode());
	auxiliaryNode->setLeftNode(avlTreeNode);
	avlTreeNode->setHeight(max(getBalanceFactor(avlTreeNode->getLeftNode()), getBalanceFactor(avlTreeNode->getRightNode())) + 1);
	auxiliaryNode->setHeight(max(getBalanceFactor(auxiliaryNode->getLeftNode()), getBalanceFactor(auxiliaryNode->getRightNode())) + 1);
	return auxiliaryNode;
}

AVLTreeNode* AVLTree::rightLeftRotation(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode* auxiliaryNode;
	avlTreeNode->setLeftNode(rightRotation(avlTreeNode->getLeftNode()));
	auxiliaryNode = leftRotation(avlTreeNode);
	return auxiliaryNode;
}

AVLTreeNode* AVLTree::leftRightRotation(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode* auxiliaryNode;
	avlTreeNode->setRightNode(leftRotation(avlTreeNode->getRightNode()));
	auxiliaryNode = rightRotation(avlTreeNode);
	return auxiliaryNode;
}
