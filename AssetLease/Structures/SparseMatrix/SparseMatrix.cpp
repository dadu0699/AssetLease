#include "SparseMatrix.h"

SparseMatrix::SparseMatrix()
{
    root = new SparseMatrixNode("-1", "-1", "ROOT");
}

SparseMatrix::~SparseMatrix()
{
}

SparseMatrixNode *SparseMatrix::searchColumn(string xDepartment)
{
    SparseMatrixNode *temp = root;

    while (temp != nullptr)
    {
        if (temp->getXDepartment() == xDepartment)
        {
            return temp;
        }
        temp = temp->getNextNode();
    }

    return nullptr;
}

SparseMatrixNode *SparseMatrix::searchRow(string yCorporation)
{
    SparseMatrixNode *temp = root;

    while (temp != nullptr)
    {
        if (temp->getYCorporation() == yCorporation)
        {
            return temp;
        }
        temp = temp->getDownNode();
    }

    return nullptr;
}

SparseMatrixNode *SparseMatrix::createColumn(string xDepartment)
{
    SparseMatrixNode *column = insertIntoColumn(new SparseMatrixNode(xDepartment, "-1", xDepartment), root);
    return column;
}

SparseMatrixNode *SparseMatrix::createRow(string yCorporation)
{
    SparseMatrixNode *row = insertIntoRow(new SparseMatrixNode("-1", yCorporation, yCorporation), root);
    return row;
}

SparseMatrixNode *SparseMatrix::insertIntoColumn(SparseMatrixNode *node, SparseMatrixNode *headerRow)
{
    SparseMatrixNode *temp = headerRow;

    while (true)
    {
        if (temp->getXDepartment() == node->getXDepartment())
        {
            return temp;
        }

        if (temp->getNextNode() != nullptr)
        {
            temp = temp->getNextNode();
        }
        else
        {
            break;
        }
    }

    temp->setNextNode(node);
    node->setPreviousNode(temp);
    return node;
}

SparseMatrixNode *SparseMatrix::insertIntoRow(SparseMatrixNode *node, SparseMatrixNode *headerColumn)
{
    SparseMatrixNode *temp = headerColumn;

    while (true)
    {
        if (temp->getYCorporation() == node->getYCorporation())
        {
            return temp;
        }

        if (temp->getDownNode() != nullptr)
        {
            temp = temp->getDownNode();
        }
        else
        {
            break;
        }
    }

    temp->setDownNode(node);
    node->setUpNode(temp);
    return node;
}

void SparseMatrix::addNode(string xDepartment, string yCorporation, User *user)
{
    SparseMatrixNode *node = new SparseMatrixNode(xDepartment, yCorporation);
    SparseMatrixNode *columnNode = searchColumn(xDepartment);
    SparseMatrixNode *rowNode = searchRow(yCorporation);

    if (columnNode == nullptr)
    {
        columnNode = createColumn(xDepartment);
    }

    if (rowNode == nullptr)
    {
        rowNode = createRow(yCorporation);
    }

    node = insertIntoColumn(node, rowNode);
    node = insertIntoRow(node, columnNode);

    if (node->getUserList()->searchNode(user->getNickname()) == nullptr)
    {
        node->getUserList()->addLastNode(user);
    }
}

void SparseMatrix::printRowHeaders()
{
    SparseMatrixNode *auxiliaryNode = root;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getYCorporation() << endl;
        auxiliaryNode = auxiliaryNode->getDownNode();
    }
}

void SparseMatrix::printColumnHeaders()
{
    SparseMatrixNode *auxiliaryNode = root;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getXDepartment() << " -> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

void SparseMatrix::printRows()
{
    SparseMatrixNode *auxiliaryRow = root->getDownNode();
    SparseMatrixNode *auxiliaryNode = auxiliaryRow;

    while (auxiliaryRow != nullptr)
    {
        cout << " ----------------------- " << endl;
        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getUserList() != nullptr)
            {
                auxiliaryNode->getUserList()->readStartNodes();
                cout << " ----> ";
            }
            auxiliaryNode = auxiliaryNode->getNextNode();
        }

        auxiliaryRow = auxiliaryRow->getDownNode();
        auxiliaryNode = auxiliaryRow;
        cout << endl;
    }
    cout << endl;
}

void SparseMatrix::printColumns()
{
    SparseMatrixNode *auxiliaryColumn = root->getNextNode();
    SparseMatrixNode *auxiliaryNode = auxiliaryColumn;

    while (auxiliaryColumn != nullptr)
    {
        cout << " ----------------------- " << endl;
        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getUserList() != nullptr)
            {
                cout << "^" << endl;
                auxiliaryNode->getUserList()->readStartNodes();
            }
            auxiliaryNode = auxiliaryNode->getDownNode();
        }

        auxiliaryColumn = auxiliaryColumn->getNextNode();
        auxiliaryNode = auxiliaryColumn;
    }
}
