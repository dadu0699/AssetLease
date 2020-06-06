#include "SparseMatrixNode.h"

SparseMatrixNode::SparseMatrixNode(string xDepartment, string yCorporation, string name)
{
	this->xDepartment = xDepartment;
	this->yCorporation = yCorporation;
	this->name = name;
	this->userList = nullptr;
}

SparseMatrixNode::SparseMatrixNode(string xDepartment, string yCorporation)
{
	this->xDepartment = xDepartment;
	this->yCorporation = yCorporation;
	this->name = "";
	this->userList = new DoubleList();
}

SparseMatrixNode::~SparseMatrixNode()
{
}

string SparseMatrixNode::getXDepartment()
{
	return xDepartment;
}

void SparseMatrixNode::setXDepartment(string xDepartment)
{
	this->xDepartment = xDepartment;
}

string SparseMatrixNode::getYCorporation()
{
	return yCorporation;
}

void SparseMatrixNode::setYCorporation(string yCorporation)
{
	this->yCorporation = yCorporation;
}

string SparseMatrixNode::getName()
{
	return name;
}

void SparseMatrixNode::setName(string name)
{
	this->name = name;
}

DoubleList *SparseMatrixNode::getUserList() const
{
	return userList;
}

void SparseMatrixNode::setUserList(DoubleList *userList)
{
	this->userList = userList;
}

SparseMatrixNode *SparseMatrixNode::getNextNode() const
{
	return nextNode;
}

void SparseMatrixNode::setNextNode(SparseMatrixNode *nextNode)
{
	this->nextNode = nextNode;
}

SparseMatrixNode *SparseMatrixNode::getPreviousNode() const
{
	return previousNode;
}

void SparseMatrixNode::setPreviousNode(SparseMatrixNode *previousNode)
{
	this->previousNode = previousNode;
}

SparseMatrixNode *SparseMatrixNode::getUpNode() const
{
	return upNode;
}

void SparseMatrixNode::setUpNode(SparseMatrixNode *upNode)
{
	this->upNode = upNode;
}

SparseMatrixNode *SparseMatrixNode::getDownNode() const
{
	return downNode;
}

void SparseMatrixNode::setDownNode(SparseMatrixNode *downNode)
{
	this->downNode = downNode;
}
