#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include "SparseMatrixNode.h"

class SparseMatrix
{
private:
    static SparseMatrix *instance;
    SparseMatrixNode *root;

    SparseMatrix();
    SparseMatrixNode *searchColumn(string xDepartment);
    SparseMatrixNode *searchRow(string yCorporation);
    SparseMatrixNode *createColumn(string xDepartment);
    SparseMatrixNode *insertIntoColumn(SparseMatrixNode *node, SparseMatrixNode *headerRow);
    SparseMatrixNode *createRow(string yCorporation);
    SparseMatrixNode *insertIntoRow(SparseMatrixNode *node, SparseMatrixNode *headerColumn);

public:
    static SparseMatrix *getInstance();
    ~SparseMatrix();

    void addNode(string xDepartment, string yCorporation, User *user);
    void report();
    SparseMatrixNode *getNode(string xDepartment, string yCorporation);

    void printRowHeaders();
    void printColumnHeaders();
    void printAssetsByDepartment(string department);
    void printColumns();
};

#endif // SPARSEMATRIX_H
