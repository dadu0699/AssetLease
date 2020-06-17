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
    while (auxiliaryNode != nullptr)
    {
        if (auxiliaryNode->getUser()->getNickname() == nickname)
        {
            return auxiliaryNode;
        }
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    return auxiliaryNode;
}

DoubleNode *DoubleList::searchNode(string nickname, string password)
{
    DoubleNode *auxiliaryNode = firstNode;
    while (auxiliaryNode != nullptr)
    {
        if (auxiliaryNode->getUser()->getNickname() == nickname && auxiliaryNode->getUser()->getPassword() == password)
        {
            return auxiliaryNode;
        }
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    return auxiliaryNode;
}

void DoubleList::report(string department, string corporation)
{
    replace(department.begin(), department.end(), ' ', '_');
    replace(corporation.begin(), corporation.end(), ' ', '_');
    if (!isEmpty())
    {
        DoubleNode *auxiliaryNode = firstNode;
        ofstream myfile(department + corporation + ".dot");
        int index = 0;

        if (myfile.is_open())
        {
            myfile << "digraph G { rankdir = LR;";
            myfile << "graph[label = \"(" + department + ", " + corporation + ")\", labelloc=t, fontsize=30];";
            myfile << "node[shape=record, style=filled fillcolor=cornsilk2];";

            while (auxiliaryNode != nullptr)
            {
                myfile << "N" << index << " [label =\""
                       << "Usuario: " << auxiliaryNode->getUser()->getNickname() << "\\n"
                       << "Nombre: " << auxiliaryNode->getUser()->getName() << "\\n"
                       << "Contrasena: " << auxiliaryNode->getUser()->getPassword()
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
            system(("dot -Tpng " + department + corporation + ".dot -o " + department + corporation + ".png").c_str());
            system((department + corporation + ".png").c_str());
        }
        else
        {
            cout << "Unable to open file";
        }
    }
}

void DoubleList::readStartNodes(string nickName, string password)
{
    if (!isEmpty())
    {
        DoubleNode *auxiliaryNode = firstNode;
        while (auxiliaryNode != nullptr)
        {
            if (!(auxiliaryNode->getUser()->getNickname() == nickName && auxiliaryNode->getUser()->getPassword() == password))
            {
                auxiliaryNode->getUser()->getAssetAVL()->inOrder();
            }
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
        cout << endl;
    }
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

string DoubleList::printAssets(string department, string corporation)
{
    string content = "";
    if (!isEmpty())
    {
        DoubleNode *auxiliaryNode = firstNode;
        while (auxiliaryNode != nullptr)
        {
            content += auxiliaryNode->getUser()->getAssetAVL()->generalReport(auxiliaryNode->getUser()->getNickname(), department, corporation);
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
        cout << endl;
    }
    return content;
}
