#include "CircularDoubleNode.h"

CircularDoubleNode::CircularDoubleNode(Lease* lease)
{
    this->lease = lease;
    nextNode = this;
    previousNode = this;
}

CircularDoubleNode::~CircularDoubleNode()
{
}

Lease* CircularDoubleNode::getLease() const
{
    return lease;
}

void CircularDoubleNode::setLease(Lease *lease)
{
    this->lease = lease;
}

CircularDoubleNode *CircularDoubleNode::getNextNode() const
{
    return nextNode;
}

void CircularDoubleNode::setNextNode(CircularDoubleNode *nextNode)
{
    this->nextNode = nextNode;
}

CircularDoubleNode *CircularDoubleNode::getPreviousNode() const
{
    return previousNode;
}

void CircularDoubleNode::setPreviousNode(CircularDoubleNode *previousNode)
{
    this->previousNode = previousNode;
}