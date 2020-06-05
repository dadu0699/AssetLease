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
    bool isEmpty();
    void report();

    void readStartNodes();
    void readEndNodes();
};

#endif // DOUBLELIST_H
