#ifndef SPARSEMATRIXNODE_H
#define SPARSEMATRIXNODE_H

#include <iostream>
using namespace std;

class SparseMatrixNode
{
private:
	string xDepartment;
	string yCorporation;
	string name;
	string data;
	SparseMatrixNode *nextNode;
	SparseMatrixNode *previousNode;
	SparseMatrixNode *upNode;
	SparseMatrixNode *downNode;

public:
	SparseMatrixNode(string xDepartment, string yCorporation, string name, string data);
	~SparseMatrixNode();

	int getXDepartment();
	void setXDepartment(string xDepartment);

	int getYCorporation();
	void setYCorporation(string yCorporation);

	int getName();
	void setName(string name);

	string getData();
	void setData(string data);

	SparseMatrixNode *getNextNode() const;
	void setNextNode(SparseMatrixNode *nextNode);

	SparseMatrixNode *getPreviousNode() const;
	void setPreviousNode(SparseMatrixNode *previousNode);

	SparseMatrixNode *getUpNode() const;
	void setUpNode(SparseMatrixNode *upNode);

	SparseMatrixNode *getDownNode() const;
	void setDownNode(SparseMatrixNode *downNode);
};

#endif //SPARSEMATRIXNODE_H
