#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <fstream>
using namespace std;

#include "DoubleNode.h"

class DoubleList
{
private:
    DoubleNode *firstNode;
    DoubleNode *lastNode;

public:
    DoubleList();
    ~DoubleList();

    DoubleNode *getFirstNode() const;
    DoubleNode *getLastNode() const;

    void addFirstNode(User *user);
    void addLastNode(User *user);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(string nickname);
    DoubleNode *searchNode(string nickname);
    DoubleNode *searchNode(string nickname, string password);
    bool isEmpty();
    void report(string department, string corporation);

    void readStartNodes(string nickName, string password);
    void readEndNodes();
    string printAssets(string department, string corporation);
};

#endif // DOUBLELIST_H
