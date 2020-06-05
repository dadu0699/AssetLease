#include "DoubleList.h"

DoubleList::DoubleList()
{
    firstNode = nullptr;
    lastNode = nullptr;
}

DoubleList::~DoubleList()
{
}

DoubleNode *DoubleList::getFirstNode() const
{
    return firstNode;
}

DoubleNode *DoubleList::getLastNode() const
{
    return lastNode;
}

bool DoubleList::isEmpty()
{
    return firstNode == nullptr;
}

void DoubleList::addFirstNode(User *user)
{
    DoubleNode *node = new DoubleNode(user);
    if (isEmpty())
    {
        lastNode = node;
    }
    else
    {
        node->setNextNode(firstNode);
        firstNode->setPreviousNode(node);
    }
    firstNode = node;
}

void DoubleList::addLastNode(User *user)
{
    DoubleNode *node = new DoubleNode(user);
    if (isEmpty())
    {
        firstNode = node;
    }
    else
    {
        node->setPreviousNode(lastNode);
        lastNode->setNextNode(node);
    }
    lastNode = node;
}

void DoubleList::deleteFirstNode()
{
    if (!isEmpty())
    {
        if (firstNode == lastNode)
        {
            firstNode = nullptr;
            lastNode = nullptr;
        }
        else
        {
            firstNode = firstNode->getNextNode();
            firstNode->setPreviousNode(nullptr);
        }
    }
}

void DoubleList::deleteLastNode()
{
    if (!isEmpty())
    {
        if (firstNode == lastNode)
        {
            firstNode = nullptr;
            lastNode = nullptr;
        }
        else
        {
            lastNode = lastNode->getPreviousNode();
            lastNode->setNextNode(nullptr);
        }
    }
}

void DoubleList::deleteSpecificNode(string nickname)
{
    if (!isEmpty())
    {
        DoubleNode *auxiliaryNode = searchNode(nickname);
        if (firstNode == auxiliaryNode)
        {
            deleteFirstNode();
        }
        else if (lastNode == auxiliaryNode)
        {
            deleteLastNode();
        }
        else
        {
            DoubleNode *previousNode = auxiliaryNode->getPreviousNode();
            DoubleNode *nextNode = auxiliaryNode->getNextNode();
            previousNode->setNextNode(nextNode);
            nextNode->setPreviousNode(previousNode);
        }
    }
}

DoubleNode *DoubleList::searchNode(string nickname)
{
    DoubleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr && auxiliaryNode->getUser()->getNickname() != nickname)
    {
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    return auxiliaryNode;
}

void DoubleList::report()
{
    if (!isEmpty())
    {
        DoubleNode *auxiliaryNode = firstNode;
        ofstream myfile("DoublyLinkedList.dot");
        int index = 0;

        if (myfile.is_open())
        {
            myfile << "digraph G { rankdir = LR;";
            myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

            while (auxiliaryNode != nullptr)
            {
                myfile << "N" << index << " [label =\""
                       << "Usuario: " << auxiliaryNode->getUser()->getNickname()
                       << "Nombre: " << auxiliaryNode->getUser()->getName()
                       //<< "Contrasena: " << auxiliaryNode->getUser()->getPassword()
                       << "\"];";
                auxiliaryNode = auxiliaryNode->getNextNode();
                index++;
            }

            for (int i = 0; i < (index - 1); i++)
            {
                myfile << "N" << i << " -> N" << (i + 1) << ";";
                myfile << "N" << (i + 1) << " -> N" << i << ";";
            }

            myfile << "}";

            myfile.close();
            system("dot -Tpng DoublyLinkedList.dot -o DoublyLinkedList.png");
            system("DoublyLinkedList.png");
        }
        else
        {
            cout << "Unable to open file";
        }
    }
}

void DoubleList::readStartNodes()
{
    DoubleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getUser()->getNickname() << " <-> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

void DoubleList::readEndNodes()
{
    DoubleNode *auxiliaryNode = lastNode;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getUser()->getNickname() << " <-> ";
        auxiliaryNode = auxiliaryNode->getPreviousNode();
    }
    cout << endl;
}