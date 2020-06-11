#include "SparseMatrix.h"

SparseMatrix::SparseMatrix()
{
    root = new SparseMatrixNode("-1", "-1", "ROOT");
}

SparseMatrix *SparseMatrix::instance = nullptr;

SparseMatrix *SparseMatrix::getInstance()
{
    if (instance == nullptr)
    {
        instance = new SparseMatrix();
    }
    return instance;
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
    bool flag = false;

    while (true)
    {
        if (temp->getXDepartment() == node->getXDepartment())
        {
            return temp;
        }
        else if (temp->getXDepartment() > node->getXDepartment())
        {
            flag = true;
            break;
        }

        if (temp->getNextNode() != nullptr)
        {
            temp = temp->getNextNode();
        }
        else
        {
            // flag = false;
            break;
        }
    }

    if (flag)
    {
        node->setNextNode(temp);
        temp->getPreviousNode()->setNextNode(node);
        node->setPreviousNode(temp->getPreviousNode());
        temp->setPreviousNode(node);
    }
    else
    {
        temp->setNextNode(node);
        node->setPreviousNode(temp);
    }
    return node;
}

SparseMatrixNode *SparseMatrix::insertIntoRow(SparseMatrixNode *node, SparseMatrixNode *headerColumn)
{
    SparseMatrixNode *temp = headerColumn;
    bool flag = false;

    while (true)
    {
        if (temp->getYCorporation() == node->getYCorporation())
        {
            return temp;
        }
        else if (temp->getYCorporation() > node->getYCorporation())
        {
            flag = true;
            break;
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

    if (flag)
    {
        node->setDownNode(temp);
        temp->getUpNode()->setDownNode(node);
        node->setUpNode(temp->getUpNode());
        temp->setUpNode(node);
    }
    else
    {
        temp->setDownNode(node);
        node->setUpNode(temp);
    }
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

void SparseMatrix::printAssetsByDepartment(string department)
{
    SparseMatrixNode *departmentNode = searchColumn(department);

    if (departmentNode != nullptr)
    {
        SparseMatrixNode *auxiliaryNode = departmentNode->getDownNode();

        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getUserList() != nullptr)
            {
                auxiliaryNode->getUserList()->printAssets(auxiliaryNode->getXDepartment(), auxiliaryNode->getYCorporation());
            }
            auxiliaryNode = auxiliaryNode->getDownNode();
        }
    }
}

void SparseMatrix::printAssetsByCorporation(string corporation)
{
    SparseMatrixNode *departmentNode = searchRow(corporation);

    if (departmentNode != nullptr)
    {
        SparseMatrixNode *auxiliaryNode = departmentNode->getNextNode();

        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getUserList() != nullptr)
            {
                auxiliaryNode->getUserList()->printAssets(auxiliaryNode->getXDepartment(), auxiliaryNode->getYCorporation());
            }
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
    }
}

void SparseMatrix::printCatalogue()
{
    SparseMatrixNode *auxiliaryColumn = root->getNextNode();
    SparseMatrixNode *auxiliaryNode = auxiliaryColumn;

    while (auxiliaryColumn != nullptr)
    {
        cout << "----- DEPARTAMENTO: " << auxiliaryColumn->getName() << endl;
        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getName().size() == 0)
            {
                cout << "------- EMPRESA: " << auxiliaryNode->getYCorporation() << endl;
                auxiliaryNode->getUserList()->readStartNodes();
            }
            auxiliaryNode = auxiliaryNode->getDownNode();
        }
        auxiliaryColumn = auxiliaryColumn->getNextNode();
        auxiliaryNode = auxiliaryColumn;
    }
}

void SparseMatrix::report()
{
    ofstream myfile("sparseMatrix.dot");

    if (myfile.is_open())
    {
        if (root != nullptr)
        {
            SparseMatrixNode *rowHeaders = root->getDownNode();
            SparseMatrixNode *columnHeaders = root->getNextNode();
            SparseMatrixNode *auxiliaryRow = root->getDownNode();
            SparseMatrixNode *auxiliaryColumn = root->getNextNode();
            SparseMatrixNode *auxiliaryNode;

            myfile << "digraph Sparce_Matrix {";
            myfile << "node [shape=box]";
            myfile << "Mt[ label = \"Matriz\", width = 1.5, style = filled, group = 1 ];";

            while (rowHeaders != nullptr)
            {
                myfile << "R" << rowHeaders->getYCorporation();
                myfile << "[label = \"" << rowHeaders->getYCorporation() << "\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque, group = 1 ];";
                rowHeaders = rowHeaders->getDownNode();
            }

            rowHeaders = root->getDownNode();
            while (rowHeaders->getDownNode() != nullptr)
            {
                myfile << "R" << rowHeaders->getYCorporation() << "-> R" << rowHeaders->getDownNode()->getYCorporation() << ";";
                rowHeaders = rowHeaders->getDownNode();
            }

            while (columnHeaders != nullptr)
            {
                myfile << "C" << columnHeaders->getXDepartment();
                myfile << "[label = \"" << columnHeaders->getXDepartment() << "\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque, group =" << columnHeaders->getXDepartment() + "2"
                       << "];";
                columnHeaders = columnHeaders->getNextNode();
            }

            columnHeaders = root->getNextNode();
            while (columnHeaders->getNextNode() != nullptr)
            {
                myfile << "C" << columnHeaders->getXDepartment() << "-> C" << columnHeaders->getNextNode()->getXDepartment() << ";";
                columnHeaders = columnHeaders->getNextNode();
            }

            myfile << "Mt -> R" << root->getDownNode()->getYCorporation() << ";";
            myfile << "Mt -> C" << root->getNextNode()->getXDepartment() << ";";

            myfile << "{ rank = same; Mt;";
            columnHeaders = root->getNextNode();
            while (columnHeaders != nullptr)
            {
                myfile << "C" << columnHeaders->getXDepartment() << ";";
                columnHeaders = columnHeaders->getNextNode();
            }
            myfile << "}";

            while (auxiliaryRow != nullptr)
            {
                auxiliaryNode = auxiliaryRow->getNextNode();
                while (auxiliaryNode != nullptr)
                {
                    myfile << "C" << auxiliaryNode->getXDepartment();
                    myfile << "R" << auxiliaryNode->getYCorporation();
                    myfile << " [label = \"" << auxiliaryNode->getUserList()->getFirstNode()->getUser()->getNickname() << "\" width = 1.5,";
                    //
                    system("pause");
                    auxiliaryNode->getUserList()->report(auxiliaryNode->getXDepartment(), auxiliaryNode->getYCorporation());
                    //
                    myfile << " style = filled, fillcolor = cornsilk2,";
                    myfile << " group = " << auxiliaryNode->getXDepartment() + "2"
                           << "];";
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }
                auxiliaryRow = auxiliaryRow->getDownNode();
            }

            auxiliaryRow = root->getDownNode();
            while (auxiliaryRow != nullptr)
            {
                auxiliaryNode = auxiliaryRow;
                while (auxiliaryNode->getNextNode() != nullptr)
                {
                    if (auxiliaryNode->getXDepartment() == "-1")
                    {
                        myfile << "R" << auxiliaryNode->getYCorporation();
                    }
                    else
                    {
                        myfile << "C" << auxiliaryNode->getXDepartment();
                        myfile << "R" << auxiliaryNode->getYCorporation();
                    }
                    myfile << " -> C" << auxiliaryNode->getNextNode()->getXDepartment();
                    myfile << "R" << auxiliaryNode->getNextNode()->getYCorporation() << " [dir=\"both\"];";
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }

                myfile << "{ rank = same; ";
                auxiliaryNode = auxiliaryRow;
                while (auxiliaryNode != nullptr)
                {
                    if (auxiliaryNode->getXDepartment() == "-1")
                    {
                        myfile << " R" << auxiliaryNode->getYCorporation() << ";";
                    }
                    else
                    {
                        myfile << " C" << auxiliaryNode->getXDepartment();
                        myfile << "R" << auxiliaryNode->getYCorporation() << ";";
                    }
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }
                myfile << "}";

                auxiliaryRow = auxiliaryRow->getDownNode();
            }

            while (auxiliaryColumn != nullptr)
            {
                auxiliaryNode = auxiliaryColumn;
                while (auxiliaryNode->getDownNode() != nullptr)
                {
                    if (auxiliaryNode->getYCorporation() == "-1")
                    {
                        myfile << "C" << auxiliaryNode->getXDepartment();
                    }
                    else
                    {
                        myfile << "C" << auxiliaryNode->getXDepartment();
                        myfile << "R" << auxiliaryNode->getYCorporation();
                    }
                    myfile << " -> C" << auxiliaryNode->getDownNode()->getXDepartment();
                    myfile << "R" << auxiliaryNode->getDownNode()->getYCorporation() << " [dir=\"both\"];";
                    auxiliaryNode = auxiliaryNode->getDownNode();
                }
                auxiliaryColumn = auxiliaryColumn->getNextNode();
            }

            myfile << "}";
            myfile.close();
            system("dot -Tpng sparseMatrix.dot -o sparseMatrix.png");
            system("sparseMatrix.png");
        }
    }
    else
    {
        cout << "Unable to open file";
    }
}

SparseMatrixNode *SparseMatrix::getNode(string xDepartment, string yCorporation)
{
    SparseMatrixNode *columnNode = searchColumn(xDepartment);
    SparseMatrixNode *rowNode = searchRow(yCorporation);

    if (columnNode != nullptr && rowNode != nullptr)
    {
        SparseMatrixNode *auxiliaryNode = root;
        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getYCorporation() == yCorporation)
            {
                break;
            }
            auxiliaryNode = auxiliaryNode->getDownNode();
        }

        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getXDepartment() == xDepartment)
            {
                return auxiliaryNode;
            }
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
    }
    return nullptr;
}
