#include "DoubleNode.h"

DoubleNode::DoubleNode(User *user)
{
    this->user = user;
    nextNode = nullptr;
    previousNode = nullptr;
}

DoubleNode::~DoubleNode()
{
}

User *DoubleNode::getUser() const
{
    return user;
}

DoubleNode *DoubleNode::getNextNode() const
{
    return nextNode;
}

void DoubleNode::setNextNode(DoubleNode *nextNode)
{
    this->nextNode = nextNode;
}

DoubleNode *DoubleNode::getPreviousNode() const
{
    return previousNode;
}

void DoubleNode::setPreviousNode(DoubleNode *previousNode)
{
    this->previousNode = previousNode;
}