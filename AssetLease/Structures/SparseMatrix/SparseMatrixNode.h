#ifndef SPARSEMATRIXNODE_H
#define SPARSEMATRIXNODE_H

#include <iostream>
#include "../../Structures/DoublyLinkedList/DoubleList.h"
using namespace std;

class SparseMatrixNode
{
private:
	string xDepartment;
	string yCorporation;
	string name;
	DoubleList *userList;
	SparseMatrixNode *nextNode;
	SparseMatrixNode *previousNode;
	SparseMatrixNode *upNode;
	SparseMatrixNode *downNode;

public:
	SparseMatrixNode(string xDepartment, string yCorporation, string name);
	SparseMatrixNode(string xDepartment, string yCorporation);
	~SparseMatrixNode();

	string getXDepartment();
	void setXDepartment(string xDepartment);

	string getYCorporation();
	void setYCorporation(string yCorporation);

	string getName();
	void setName(string name);

	DoubleList *getUserList() const;
	void setUserList(DoubleList *userList);

	SparseMatrixNode *getNextNode() const;
	void setNextNode(SparseMatrixNode *nextNode);

	SparseMatrixNode *getPreviousNode() const;
	void setPreviousNode(SparseMatrixNode *previousNode);

	SparseMatrixNode *getUpNode() const;
	void setUpNode(SparseMatrixNode *upNode);

	SparseMatrixNode *getDownNode() const;
	void setDownNode(SparseMatrixNode *downNode);
};

#endif // SPARSEMATRIXNODE_H
