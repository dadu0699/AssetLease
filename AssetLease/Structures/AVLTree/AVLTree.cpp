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

int AVLTree::updateHeight(AVLTreeNode *avlTreeNode)
{
	if (avlTreeNode != nullptr)
	{
		return avlTreeNode->getHeight();
	}
	return 0;
}

int AVLTree::getBalanceFactor(AVLTreeNode *avlTreeNode)
{
	if (avlTreeNode != nullptr)
	{
		return updateHeight(avlTreeNode->getRightNode()) - updateHeight(avlTreeNode->getLeftNode());
	}
	return 0;
}

AVLTreeNode *AVLTree::leftRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode = avlTreeNode->getRightNode();
	avlTreeNode->setRightNode(auxiliaryNode->getLeftNode());
	auxiliaryNode->setLeftNode(avlTreeNode);

	avlTreeNode->setHeight(max(updateHeight(avlTreeNode->getLeftNode()), updateHeight(avlTreeNode->getRightNode())) + 1);
	auxiliaryNode->setHeight(max(updateHeight(auxiliaryNode->getLeftNode()), updateHeight(auxiliaryNode->getRightNode())) + 1);
	return auxiliaryNode;
}

AVLTreeNode *AVLTree::rightRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode = avlTreeNode->getLeftNode();
	avlTreeNode->setLeftNode(auxiliaryNode->getRightNode());
	auxiliaryNode->setRightNode(avlTreeNode);

	avlTreeNode->setHeight(max(updateHeight(avlTreeNode->getLeftNode()), updateHeight(avlTreeNode->getRightNode())) + 1);
	auxiliaryNode->setHeight(max(updateHeight(auxiliaryNode->getLeftNode()), updateHeight(auxiliaryNode->getRightNode())) + 1);
	return auxiliaryNode;
}

AVLTreeNode *AVLTree::leftRightRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode;
	avlTreeNode->setLeftNode(leftRotation(avlTreeNode->getLeftNode()));
	auxiliaryNode = rightRotation(avlTreeNode);
	return auxiliaryNode;
}

AVLTreeNode *AVLTree::rightLeftRotation(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *auxiliaryNode;
	avlTreeNode->setRightNode(rightRotation(avlTreeNode->getRightNode()));
	auxiliaryNode = leftRotation(avlTreeNode);
	return auxiliaryNode;
}

void AVLTree::insert(Asset *asset)
{
	AVLTreeNode *newNode = new AVLTreeNode(asset);
	root = insert(newNode, root);
}

AVLTreeNode *AVLTree::insert(AVLTreeNode *newNode, AVLTreeNode *avlTreeNode)
{
	if (avlTreeNode == nullptr)
	{
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
		return avlTreeNode;
	}

	avlTreeNode->setHeight(1 + max(updateHeight(avlTreeNode->getLeftNode()), updateHeight(avlTreeNode->getRightNode())));
	int balanceFactor = getBalanceFactor(avlTreeNode);

	if (balanceFactor < -1)
	{
		if (newNode->getAsset()->getIdentifier() < avlTreeNode->getLeftNode()->getAsset()->getIdentifier())
		{
			return rightRotation(avlTreeNode);
		}
		else if (newNode->getAsset()->getIdentifier() > avlTreeNode->getLeftNode()->getAsset()->getIdentifier())
		{
			return leftRightRotation(avlTreeNode);
		}
	}
	else if (balanceFactor > 1)
	{
		if (newNode->getAsset()->getIdentifier() > avlTreeNode->getRightNode()->getAsset()->getIdentifier())
		{
			return leftRotation(avlTreeNode);
		}
		else if (newNode->getAsset()->getIdentifier() < avlTreeNode->getRightNode()->getAsset()->getIdentifier())
		{
			return rightLeftRotation(avlTreeNode);
		}
	}
	return avlTreeNode;
}

void AVLTree::deleteNode(string identifier)
{
	root = deleteNode(root, identifier);
}

AVLTreeNode *AVLTree::nodeWithMinimumValue(AVLTreeNode *avlTreeNode)
{
	AVLTreeNode *current = avlTreeNode->getRightNode();
	while (current->getLeftNode() != nullptr)
	{
		current = current->getLeftNode();
	}
	return current;
}

AVLTreeNode *AVLTree::deleteNode(AVLTreeNode *avlTreeNode, string identifier)
{
	if (avlTreeNode == nullptr)
	{
		return nullptr;
	}

	if (identifier < avlTreeNode->getAsset()->getIdentifier())
	{
		avlTreeNode->setLeftNode(deleteNode(avlTreeNode->getLeftNode(), identifier));
	}
	else if (identifier > avlTreeNode->getAsset()->getIdentifier())
	{
		avlTreeNode->setRightNode(deleteNode(avlTreeNode->getRightNode(), identifier));
	}
	else
	{
		if (avlTreeNode->getLeftNode() == nullptr || avlTreeNode->getRightNode() == nullptr)
		{
			if (avlTreeNode->getLeftNode() == nullptr && avlTreeNode->getRightNode() == nullptr)
			{
				avlTreeNode = nullptr;
			}
			else
			{
				AVLTreeNode *auxiliaryNode;
				if (avlTreeNode->getLeftNode() == nullptr)
				{
					auxiliaryNode = avlTreeNode->getRightNode();
				}
				else
				{
					auxiliaryNode = avlTreeNode->getLeftNode();
				}
				avlTreeNode = auxiliaryNode;
			}
		}
		else
		{
			AVLTreeNode *auxiliaryNode = nodeWithMinimumValue(avlTreeNode);
			avlTreeNode->setAsset(auxiliaryNode->getAsset());
			avlTreeNode->setRightNode(deleteNode(avlTreeNode->getRightNode(), auxiliaryNode->getAsset()->getIdentifier()));
		}
	}

	if (avlTreeNode == nullptr)
	{
		return nullptr;
	}

	avlTreeNode->setHeight(max(updateHeight(avlTreeNode->getLeftNode()), updateHeight(avlTreeNode->getRightNode())) + 1);
	int balanceFactor = getBalanceFactor(avlTreeNode);

	if (balanceFactor < -1)
	{
		if (getBalanceFactor(avlTreeNode->getLeftNode()) > 0)
		{
			avlTreeNode->setLeftNode(leftRotation(avlTreeNode->getLeftNode()));
		}
		return rightRotation(avlTreeNode);
	}
	else if (balanceFactor > 1)
	{
		if (getBalanceFactor(avlTreeNode->getRightNode()) < 0)
		{
			avlTreeNode->setRightNode(rightRotation(avlTreeNode->getRightNode()));
		}
		return leftRotation(avlTreeNode);
	}
	return avlTreeNode;
}

AVLTreeNode *AVLTree::search(string identifier)
{
	return search(identifier, root);
}

AVLTreeNode *AVLTree::search(string identifier, AVLTreeNode *avlTreeNode)
{
	if (avlTreeNode != nullptr)
	{
		if (identifier < avlTreeNode->getAsset()->getIdentifier())
		{
			return search(identifier, avlTreeNode->getLeftNode());
		}
		else if (identifier > avlTreeNode->getAsset()->getIdentifier())
		{
			return search(identifier, avlTreeNode->getRightNode());
		}
		else
		{
			return avlTreeNode;
		}
	}
	return nullptr;
}

void AVLTree::inOrder()
{
	inOrder(root);
}

void AVLTree::inOrder(AVLTreeNode *root)
{
	if (root != nullptr)
	{
		inOrder(root->getLeftNode());
		if (!root->getAsset()->getLease())
		{
			cout << ">> ID = " << root->getAsset()->getIdentifier() << "; "
				 << "Nombre = " << root->getAsset()->getName() << "; "
				 << "Descripcion = " << root->getAsset()->getDescription() << "; "
				 << endl;
		}
		inOrder(root->getRightNode());
	}
}

void AVLTree::inOrderM()
{
	inOrderM(root);
}

void AVLTree::inOrderM(AVLTreeNode *root)
{
	if (root != nullptr)
	{
		inOrderM(root->getLeftNode());
		if (root->getAsset()->getLease())
		{
			cout << ">> ID = " << root->getAsset()->getIdentifier() << "; "
				 << "Nombre = " << root->getAsset()->getName() << "; "
				 << "Descripcion = " << root->getAsset()->getDescription() << "; "
				 << endl;
		}
		inOrderM(root->getRightNode());
	}
}

string AVLTree::report(AVLTreeNode *root)
{
	string myfile;
	if (!isEmpty())
	{
		int indexParentNode = indexNode;
		myfile.append("N" + to_string(indexNode));
		myfile.append("[label=\"ID: " + root->getAsset()->getIdentifier() + "\\n");
		myfile.append("Nombre: " + root->getAsset()->getName() + "\\n");
		myfile.append("Descripcion: " + root->getAsset()->getDescription() + "\"");
		if (root->getAsset()->getLease())
		{
			myfile.append("style=filled color=\"#f8d7da\" fillcolor=\"#f8d7da\", fontcolor = \"#721c57\"");
		}
		myfile.append("]; ");

		if (root->getLeftNode() != nullptr)
		{
			myfile.append(reportLeftNode(root, indexParentNode));
		}

		if (root->getRightNode() != nullptr)
		{
			myfile.append(reportRightNode(root, indexParentNode));
		}
	}
	return myfile;
}

string AVLTree::generalReport(AVLTreeNode *root)
{
	string myfile;
	if (root != nullptr)
	{
		myfile.append("N" + root->getAsset()->getIdentifier());
		myfile.append("[label=\"ID: " + root->getAsset()->getIdentifier() + "\\n");
		myfile.append("Nombre: " + root->getAsset()->getName() + "\\n");
		myfile.append("Descripcion: " + root->getAsset()->getDescription() + "\"");
		if (root->getAsset()->getLease())
		{
			myfile.append("style=filled color=\"#f8d7da\" fillcolor=\"#f8d7da\", fontcolor = \"#721c57\"");
		}
		myfile.append("]; ");

		if (root->getLeftNode() != nullptr)
		{
			myfile.append(generalReport(root->getLeftNode()));
			myfile.append("N" + root->getAsset()->getIdentifier());
			myfile.append(" -> N" + root->getLeftNode()->getAsset()->getIdentifier() + "; ");
		}

		if (root->getRightNode() != nullptr)
		{
			myfile.append(generalReport(root->getRightNode()));
			myfile.append("N" + root->getAsset()->getIdentifier());
			myfile.append(" -> N" + root->getRightNode()->getAsset()->getIdentifier() + "; ");
		}
	}
	return myfile;
}

string AVLTree::reportLeftNode(AVLTreeNode *root, int indexParentNode)
{
	string myfile;
	indexNode++;
	int indexLeftNode = indexNode;
	myfile.append(report(root->getLeftNode()));
	myfile.append("N" + to_string(indexParentNode));
	myfile.append(" -> N" + to_string(indexLeftNode) + "; ");
	return myfile;
}

string AVLTree::reportRightNode(AVLTreeNode *root, int indexParentNode)
{
	string myfile;
	indexNode++;
	int indexRightNode = indexNode;
	myfile.append(report(root->getRightNode()));
	myfile.append("N" + to_string(indexParentNode));
	myfile.append(" -> N" + to_string(indexRightNode) + "; ");
	return myfile;
}

void AVLTree::report(string user, string department, string corporation)
{
	replace(department.begin(), department.end(), ' ', '_');
	replace(corporation.begin(), corporation.end(), ' ', '_');
	ofstream myfile(user + department + corporation + ".dot");

	if (myfile.is_open())
	{
		myfile << "digraph G { ";
		myfile << "node[style=filled fillcolor=cornsilk2];";
		myfile << "graph[label = \"(" + user + ", " + department + ", " + corporation + ")\", labelloc=t, fontsize=30];";
		indexNode = 0;
		myfile << report(root);
		myfile << " }";
		myfile.close();
		system(("dot -Tpng " + user + department + corporation + ".dot -o " + user + department + corporation + ".png").c_str());
		system((user + department + corporation + ".png").c_str());
	}
	else
	{
		cout << "Unable to open file";
	}
}

string AVLTree::generalReport(string user, string department, string corporation)
{
	replace(department.begin(), department.end(), ' ', '_');
	replace(corporation.begin(), corporation.end(), ' ', '_');
	return "subgraph cluster_" + user + department + corporation + "{label = \"(" + user + ", " + department + ", " + corporation + ")\";" + generalReport(root) + "}";
}
