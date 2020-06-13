#include "CircularDoubleList.h"

CircularDoubleList::CircularDoubleList()
{
	firstNode = nullptr;
	lastNode = nullptr;
}

CircularDoubleList *CircularDoubleList::instance = nullptr;

CircularDoubleList *CircularDoubleList::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CircularDoubleList();
	}
	return instance;
}

CircularDoubleList::~CircularDoubleList()
{
}

bool CircularDoubleList::isEmpty()
{
	return firstNode == nullptr;
}

void CircularDoubleList::addNode(Lease *lease)
{
	CircularDoubleNode *newNode = new CircularDoubleNode(lease);

	if (firstNode == nullptr)
	{
		firstNode = newNode;
		lastNode = newNode;

		firstNode->setNextNode(lastNode);
		lastNode->setNextNode(firstNode);

		firstNode->setPreviousNode(lastNode);
		lastNode->setPreviousNode(firstNode);
	}
	else
	{
		newNode->setPreviousNode(lastNode);
		newNode->setNextNode(firstNode);

		lastNode->setNextNode(newNode);
		firstNode->setPreviousNode(newNode);

		lastNode = newNode;
	}
}

void CircularDoubleList::readStartNodes(User *user)
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = firstNode;
		do
		{
			if (auxiliaryNode->getLease()->getUser()->getName() == user->getName() && auxiliaryNode->getLease()->getState())
			{
				cout << "ID: " << auxiliaryNode->getLease()->getIdentifier();
				cout << " NOMBRE: " << auxiliaryNode->getLease()->getAsset()->getIdentifier()
					 << " " << auxiliaryNode->getLease()->getAsset()->getName();
				cout << " TIEMPO RENTA: " << auxiliaryNode->getLease()->getIdentifier();
				cout << endl;
			}
			auxiliaryNode = auxiliaryNode->getNextNode();
		} while (auxiliaryNode != firstNode);
	}
}

void CircularDoubleList::deleteSpecificNode(string identifier)
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = searchNode(identifier);

		if (auxiliaryNode != nullptr) 
		{
			auxiliaryNode->getLease()->getAsset()->setLease(false);
			auxiliaryNode->getLease()->setState(false);
		}

		/*
		if (firstNode == auxiliaryNode)
		{
			if (firstNode == lastNode)
			{
				firstNode = nullptr;
				lastNode = nullptr;
			}
			else
			{
				firstNode = firstNode->getNextNode();
				firstNode->setPreviousNode(lastNode);
				lastNode->setNextNode(firstNode);
			}
		}
		else if (lastNode == auxiliaryNode)
		{
			if (firstNode == lastNode)
			{
				firstNode = nullptr;
				lastNode = nullptr;
			}
			else
			{
				lastNode = lastNode->getPreviousNode();
				lastNode->setNextNode(firstNode);
				firstNode->setPreviousNode(lastNode);
			}
		}
		else
		{
			CircularDoubleNode *previousNode = auxiliaryNode->getPreviousNode();
			CircularDoubleNode *nextNode = auxiliaryNode->getNextNode();
			previousNode->setNextNode(nextNode);
			nextNode->setPreviousNode(previousNode);
		}
		*/
	}
}

CircularDoubleNode *CircularDoubleList::searchNode(string identifier)
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = firstNode;
		string auxWord;
		do
		{
			auxWord = auxiliaryNode->getLease()->getIdentifier();

			if (identifier == auxWord)
			{
				return auxiliaryNode;
			}
			else
			{
				auxiliaryNode = auxiliaryNode->getNextNode();
			}
		} while (auxiliaryNode != firstNode);
	}

	return nullptr;
}

void CircularDoubleList::report()
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = firstNode;
		ofstream myfile("CircularDoublyLinkedList.dot");
		int index = 0;

		if (myfile.is_open())
		{
			myfile << "digraph G { rankdir = LR;";
			myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

			do
			{
				// cout << auxiliaryNode->getLease()->getIdentifier() << " - ";
				myfile << "N" << index;
				myfile << "[label=\"ID: " << auxiliaryNode->getLease()->getIdentifier() << "\\n";
				myfile << "Activo: " << auxiliaryNode->getLease()->getAsset()->getIdentifier() << " "
					   << auxiliaryNode->getLease()->getAsset()->getName() << "\\n";
				myfile << "Fecha: " << auxiliaryNode->getLease()->getLeaseDate() << "\\n";
				myfile << "Usuario: " << auxiliaryNode->getLease()->getUser()->getName() << "\\n";
				myfile << "Devolucion: " << auxiliaryNode->getLease()->getreturnDate() << "\"";
				myfile << "]; ";
				auxiliaryNode = auxiliaryNode->getNextNode();
				index++;
			} while (auxiliaryNode != firstNode);

			for (int i = 0; i < (index - 1); i++)
			{
				myfile << "N" << i << " -> N" << (i + 1) << ";";
				myfile << "N" << (i + 1) << " -> N" << i << ";";
			}
			myfile << "N" << 0 << " -> N" << (index - 1) << ";";
			myfile << "N" << (index - 1) << " -> N" << 0 << ";";

			myfile << "}";

			myfile.close();
			system("dot -Tpng CircularDoublyLinkedList.dot -o CircularDoublyLinkedList.png");
			system("CircularDoublyLinkedList.png");
		}
		else
		{
			cout << "Unable to open file";
		}
	}
}

void CircularDoubleList::report(string department, string corporation, string user)
{
	if (!isEmpty())
	{
		CircularDoubleNode *auxiliaryNode = firstNode;
		ofstream myfile("CircularDoublyLinkedList.dot");
		int index = 0;

		if (myfile.is_open())
		{
			myfile << "digraph G { rankdir = LR;";
			myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

			do
			{
				if (auxiliaryNode->getLease()->getDepartment() == department && auxiliaryNode->getLease()->getCorporation() == corporation && auxiliaryNode->getLease()->getUser()->getNickname() == user)
				{
					myfile << "N" << index;
					myfile << "[label=\"ID: " << auxiliaryNode->getLease()->getIdentifier() << "\\n";
					myfile << "Activo: " << auxiliaryNode->getLease()->getAsset()->getIdentifier() << " "
						   << auxiliaryNode->getLease()->getAsset()->getName() << "\\n";
					myfile << "Fecha: " << auxiliaryNode->getLease()->getLeaseDate() << "\\n";
					myfile << "Departamento: " << auxiliaryNode->getLease()->getDepartment() << "\\n";
					myfile << "Empresa: " << auxiliaryNode->getLease()->getCorporation() << "\\n";
					myfile << "Usuario: " << auxiliaryNode->getLease()->getUser()->getName() << "\\n";
					myfile << "Devolucion: " << auxiliaryNode->getLease()->getreturnDate() << "\"";
					myfile << "]; ";
					index++;
				}
				auxiliaryNode = auxiliaryNode->getNextNode();

			} while (auxiliaryNode != firstNode);

			if (index > 1)
			{
				for (int i = 0; i < (index - 1); i++)
				{
					myfile << "N" << i << " -> N" << (i + 1) << ";";
					myfile << "N" << (i + 1) << " -> N" << i << ";";
				}
				myfile << "N" << 0 << " -> N" << (index - 1) << ";";
				myfile << "N" << (index - 1) << " -> N" << 0 << ";";
			}

			myfile << "}";

			myfile.close();
			system("dot -Tpng CircularDoublyLinkedList.dot -o CircularDoublyLinkedList.png");
			system("CircularDoublyLinkedList.png");
		}
		else
		{
			cout << "Unable to open file";
		}
	}
}

void CircularDoubleList::sortAscending()
{
	CircularDoubleNode *current;
	CircularDoubleNode *index;
	Lease *temp;

	if (!isEmpty())
	{
		for (current = firstNode; current->getNextNode() != firstNode; current = current->getNextNode())
		{
			// cout << " * " << current->getLease()->getIdentifier() << endl;
			for (index = current->getNextNode(); index != firstNode; index = index->getNextNode())
			{
				// cout << "   - " << current->getLease()->getIdentifier() << " > " << index->getLease()->getIdentifier() << endl;
				if (current->getLease()->getIdentifier() > index->getLease()->getIdentifier())
				{
					temp = current->getLease();
					current->setLease(index->getLease());
					index->setLease(temp);
					// cout << "    CAMBIO " << current->getLease()->getIdentifier() << " > " << index->getLease()->getIdentifier() << endl;
				}
			}
		}
	}
}

void CircularDoubleList::sortDescending()
{
	CircularDoubleNode *current;
	CircularDoubleNode *index;
	Lease *temp;

	if (!isEmpty())
	{
		for (current = firstNode; current->getNextNode() != firstNode; current = current->getNextNode())
		{
			for (index = current->getNextNode(); index != firstNode; index = index->getNextNode())
			{
				if (current->getLease()->getIdentifier() < index->getLease()->getIdentifier())
				{
					temp = current->getLease();
					current->setLease(index->getLease());
					index->setLease(temp);
				}
			}
		}
	}
}
