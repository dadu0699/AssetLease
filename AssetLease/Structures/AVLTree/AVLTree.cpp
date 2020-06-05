#include "AVLTree.h"

AVLTree::AVLTree()
{
	root = nullptr;
	indexNode = 0;
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

AVLTreeNode *AVLTree::rightRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode = avlTreeNode->getRightNode();
	avlTreeNode->setRightNode(auxiliaryNode->getLeftNode());
	auxiliaryNode->setLeftNode(avlTreeNode);
	avlTreeNode->setHeight(max(getBalanceFactor(avlTreeNode->getLeftNode()), getBalanceFactor(avlTreeNode->getRightNode())) + 1);
	auxiliaryNode->setHeight(max(getBalanceFactor(auxiliaryNode->getLeftNode()), getBalanceFactor(auxiliaryNode->getRightNode())) + 1);
	return auxiliaryNode;
}

AVLTreeNode *AVLTree::rightLeftRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode;
	avlTreeNode->setLeftNode(rightRotation(avlTreeNode->getLeftNode()));
	auxiliaryNode = leftRotation(avlTreeNode);
	return auxiliaryNode;
}

AVLTreeNode *AVLTree::leftRightRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode;
	avlTreeNode->setRightNode(leftRotation(avlTreeNode->getRightNode()));
	auxiliaryNode = rightRotation(avlTreeNode);
	return auxiliaryNode;
}

void AVLTree::insert(Asset *asset)
{
	AVLTreeNode *newNode = new AVLTreeNode(asset);
	if (isEmpty())
	{
		root = newNode;
	}
	else
	{
		root = insert(newNode, root);
	}
}

AVLTreeNode *AVLTree::insert(AVLTreeNode *newNode, AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *newRoot = avlTreeNode;
	if (newNode->getAsset()->getIdentifier() < avlTreeNode->getAsset()->getIdentifier())
	{
		if (avlTreeNode->getLeftNode() == nullptr)
		{
			avlTreeNode->setLeftNode(newNode);
		}
		else
		{
			avlTreeNode->setLeftNode(insert(newNode, avlTreeNode->getLeftNode()));

			int balanceFactor = getBalanceFactor(avlTreeNode->getLeftNode()) - getBalanceFactor(avlTreeNode->getRightNode());
			if (balanceFactor == 2)
			{
				if (newNode->getAsset()->getIdentifier() < avlTreeNode->getAsset()->getIdentifier())
				{
					newRoot = leftRotation(avlTreeNode);
				}
				else
				{
					newRoot = rightLeftRotation(avlTreeNode);
				}
			}
		}
	}
	else if (newNode->getAsset()->getIdentifier() > avlTreeNode->getAsset()->getIdentifier())
	{
		if (avlTreeNode->getRightNode() == nullptr)
		{
			avlTreeNode->setRightNode(newNode);
		}
		else
		{
			avlTreeNode->setRightNode(insert(newNode, avlTreeNode->getRightNode()));

			int balanceFactor = getBalanceFactor(avlTreeNode->getRightNode()) - getBalanceFactor(avlTreeNode->getLeftNode());
			if (balanceFactor == 2)
			{
				if (newNode->getAsset()->getIdentifier() > avlTreeNode->getAsset()->getIdentifier())
				{
					newRoot = rightRotation(avlTreeNode);
				}
				else
				{
					newRoot = leftRightRotation(avlTreeNode);
				}
			}
		}
	}
	else
	{
		cout << "Duplicated";
	}

	if (avlTreeNode->getLeftNode() == nullptr && avlTreeNode->getRightNode() != nullptr)
	{
		avlTreeNode->setHeight(avlTreeNode->getRightNode()->getHeight() + 1);
	}
	else if (avlTreeNode->getLeftNode() != nullptr && avlTreeNode->getRightNode() == nullptr)
	{
		avlTreeNode->setHeight(avlTreeNode->getLeftNode()->getHeight() + 1);
	}
	else
	{
		avlTreeNode->setHeight(max(getBalanceFactor(avlTreeNode->getLeftNode()), getBalanceFactor(avlTreeNode->getRightNode()) + 1));
	}
	return newRoot;
}

string AVLTree::report(AVLTreeNode* root)
{
	string myfile;
	if (!isEmpty())
	{
		int indexParentNode = indexNode;
		myfile.append("N" + to_string(indexNode) + "[label = \"" 
			+ "ID: "+ root->getAsset()->getIdentifier() + "\\n"
			+ "Nombre: "+ root->getAsset()->getName() + "\\n"
			+ "Descripcion: "+ root->getAsset()->getDescription() + "\"]; ");

		if (root->getLeftNode() != nullptr)
		{
			indexNode++;
			int indexLeftNode = indexNode;
			myfile.append(report(root->getLeftNode()));
			myfile.append("N" + to_string(indexParentNode) + " -> N" + to_string(indexLeftNode) + "; ");
		}

		if (root->getRightNode() != nullptr)
		{
			indexNode++;
			int indexRightNode = indexNode;
			myfile.append(report(root->getRightNode()));
			myfile.append("N" + to_string(indexParentNode) + " -> N" + to_string(indexRightNode) + "; ");
		}
	}
	return myfile;
}

void AVLTree::report()
{
	ofstream myfile("AVLTree.dot");

	if (myfile.is_open())
	{
		if (!isEmpty())
		{
			myfile << "digraph G { ";

			indexNode = 0;
			myfile << report(root);

			myfile << " }";
			myfile.close();
			system("dot -Tpng AVLTree.dot -o AVLTree.png");
			system("AVLTree.png");
		}
	}
	else
	{
		cout << "Unable to open file";
	}
}
