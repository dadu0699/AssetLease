#ifndef CIRCULARDOUBLENODE_H
#define CIRCULARDOUBLENODE_H

#include <iostream>
#include "../../Models/Lease.h"
using namespace std;

class CircularDoubleNode
{
private:
    Lease* lease;
    CircularDoubleNode *nextNode;
    CircularDoubleNode *previousNode;

public:
    CircularDoubleNode(Lease* lease);
    ~CircularDoubleNode();

    Lease* getLease() const;
    void setLease(Lease* lease);

    CircularDoubleNode *getNextNode() const;
    void setNextNode(CircularDoubleNode *nextNode);

    CircularDoubleNode *getPreviousNode() const;
    void setPreviousNode(CircularDoubleNode *previousNode);
};

#endif // CIRCULARDOUBLENODE_H
