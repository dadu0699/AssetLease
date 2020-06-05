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

int AVLTree::updateHeight(AVLTreeNode* avlTreeNode)
{
	if (avlTreeNode != nullptr) {
		return avlTreeNode->getHeight();
	}
	return 0;
}

int AVLTree::getBalanceFactor(AVLTreeNode *avlTreeNode)
{
	if (avlTreeNode != nullptr) {
		return updateHeight(avlTreeNode->getRightNode()) - updateHeight(avlTreeNode->getLeftNode());
	}
	return 0;
}

AVLTreeNode *AVLTree::nodeWithMinimumValue(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode*current = avlTreeNode;
	while (current->getLeftNode() != nullptr) {
		current = current->getLeftNode();
	}
	return current;
}

AVLTreeNode *AVLTree::leftRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode* auxiliaryNode = avlTreeNode->getRightNode();
	avlTreeNode->setRightNode(auxiliaryNode->getLeftNode());
	auxiliaryNode->setLeftNode(avlTreeNode);

	avlTreeNode->setHeight(max(updateHeight(avlTreeNode->getLeftNode()), updateHeight(avlTreeNode->getRightNode())) + 1);
	auxiliaryNode->setHeight(max(updateHeight(auxiliaryNode->getLeftNode()), updateHeight(auxiliaryNode->getRightNode())) + 1);
	return auxiliaryNode;
}

AVLTreeNode *AVLTree::rightRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode* auxiliaryNode = avlTreeNode->getLeftNode();
	avlTreeNode->setLeftNode(auxiliaryNode->getRightNode());
	auxiliaryNode->setRightNode(avlTreeNode);

	avlTreeNode->setHeight(max(updateHeight(avlTreeNode->getLeftNode()), updateHeight(avlTreeNode->getRightNode())) + 1);
	auxiliaryNode->setHeight(max(updateHeight(auxiliaryNode->getLeftNode()), updateHeight(auxiliaryNode->getRightNode())) + 1);
	return auxiliaryNode;
}

AVLTreeNode* AVLTree::leftRightRotation(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode* auxiliaryNode;
	avlTreeNode->setLeftNode(leftRotation(avlTreeNode->getLeftNode()));
	auxiliaryNode = rightRotation(avlTreeNode);
	return auxiliaryNode;
}

AVLTreeNode* AVLTree::rightLeftRotation(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode* auxiliaryNode;
	avlTreeNode->setRightNode(rightRotation(avlTreeNode->getRightNode()));
	auxiliaryNode = leftRotation(avlTreeNode);
	return auxiliaryNode;
}

void AVLTree::insert(Asset *asset)
{
	AVLTreeNode* newNode = new AVLTreeNode(asset);
	root = insert(newNode, root);
}

AVLTreeNode *AVLTree::insert(AVLTreeNode *newNode, AVLTreeNode *avlTreeNode)
{
	if (avlTreeNode == nullptr) {
		return newNode;
	}

	if (newNode->getAsset()->getIdentifier() < avlTreeNode->getAsset()->getIdentifier())
	{
		avlTreeNode->setLeftNode(insert(newNode, avlTreeNode->getLeftNode()));
	}
	else if (newNode->getAsset()->getIdentifier() > avlTreeNode->getAsset()->getIdentifier())
	{
		avlTreeNode->setRightNode(insert(newNode, avlTreeNode->getRightNode()));
	}
	else
	{
		cout << "Duplicated";
		return newNode;
	}

	avlTreeNode->setHeight(1 + max(updateHeight(avlTreeNode->getLeftNode()), updateHeight(avlTreeNode->getRightNode())));
	int balanceFactor = getBalanceFactor(avlTreeNode);

	if (balanceFactor < 1) {
		if (newNode->getAsset()->getIdentifier() < avlTreeNode->getLeftNode()->getAsset()->getIdentifier()) {
			return rightRotation(avlTreeNode);
		}
		else if (newNode->getAsset()->getIdentifier() > avlTreeNode->getLeftNode()->getAsset()->getIdentifier()) {
			return leftRightRotation(avlTreeNode);
		}
	}
	else if (balanceFactor > 1) 
	{
		if (newNode->getAsset()->getIdentifier() > avlTreeNode->getRightNode()->getAsset()->getIdentifier()) {
			return leftRotation(avlTreeNode);
		}
		else if (newNode->getAsset()->getIdentifier() < avlTreeNode->getRightNode()->getAsset()->getIdentifier()) {
			return rightLeftRotation(avlTreeNode);
		}
	}
	return avlTreeNode;
}

AVLTreeNode* AVLTree::search(string identifier, AVLTreeNode* avlTreeNode)
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

string AVLTree::report(AVLTreeNode *root)
{
	string myfile;
	if (!isEmpty())
	{
		int indexParentNode = indexNode;
		myfile.append("N" + to_string(indexNode) + "[label = \"" + "ID: " 
			+ root->getAsset()->getIdentifier() + "\\n" 
			+ "Nombre: " + root->getAsset()->getName() + "\\n" 
			+ "Descripcion: " + root->getAsset()->getDescription() + "\"]; ");

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
