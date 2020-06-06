#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include "SparseMatrixNode.h"

class SparseMatrix
{
private:
    SparseMatrixNode *root;

    SparseMatrixNode *searchColumn(string xDepartment);
    SparseMatrixNode *searchRow(string yCorporation);
    SparseMatrixNode *createColumn(string xDepartment);
    SparseMatrixNode *insertIntoColumn(SparseMatrixNode *node, SparseMatrixNode *headerRow);
    SparseMatrixNode *createRow(string yCorporation);
    SparseMatrixNode *insertIntoRow(SparseMatrixNode *node, SparseMatrixNode *headerColumn);

public:
    SparseMatrix();
    ~SparseMatrix();

    void addNode(string xDepartment, string yCorporation, User *user);
    void report();
    SparseMatrixNode *getNode(int xDepartment, int yCorporation);

    void printRowHeaders();
    void printColumnHeaders();
    void printRows();
    void printColumns();
};

#endif // SPARSEMATRIX_H
