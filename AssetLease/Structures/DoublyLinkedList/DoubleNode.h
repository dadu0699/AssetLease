#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include "../../Models/User.h"

class DoubleNode
{
private:
    User *user;
    DoubleNode *nextNode;
    DoubleNode *previousNode;

public:
    DoubleNode(User *user);
    ~DoubleNode();

    User *getUser() const;

    DoubleNode *getNextNode() const;
    void setNextNode(DoubleNode *nextNode);

    DoubleNode *getPreviousNode() const;
    void setPreviousNode(DoubleNode *previousNode);
};

#endif // DOUBLENODE_H
