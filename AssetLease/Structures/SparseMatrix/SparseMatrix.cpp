#include "SparseMatrix.h"

SparseMatrix::SparseMatrix()
{
    root = new SparseMatrixNode("-1", "-1", "ROOT");
}

string SparseMatrix::replaceSpaces(string content)
{
    replace(content.begin(), content.end(), ' ', '_');
    return content;
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
    return insertIntoColumn(new SparseMatrixNode(xDepartment, "-1", xDepartment), root);
}

SparseMatrixNode *SparseMatrix::createRow(string yCorporation)
{
    return insertIntoRow(new SparseMatrixNode("-1", yCorporation, yCorporation), root);
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
        else if (temp->getXDepartment() > node->getXDepartment())
        {
            node->setNextNode(temp);
            temp->getPreviousNode()->setNextNode(node);
            node->setPreviousNode(temp->getPreviousNode());
            temp->setPreviousNode(node);
            return node;
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
        else if (temp->getYCorporation() > node->getYCorporation())
        {
            node->setDownNode(temp);
            temp->getUpNode()->setDownNode(node);
            node->setUpNode(temp->getUpNode());
            temp->setUpNode(node);
            return node;
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

void SparseMatrix::generateReport(string name, string content)
{
    replace(name.begin(), name.end(), ' ', '_');
    ofstream myfile(name + ".dot");

    if (myfile.is_open())
    {
        myfile << "digraph G { ";
        myfile << "node[style=filled fillcolor=cornsilk2];";
        myfile << "graph[label = \"" + name + "\", labelloc=t, fontsize=30];";
        myfile << content;
        myfile << " }";
        myfile.close();
        system(("dot -Tpng " + name + ".dot -o " + name + ".png").c_str());
        system((name + ".png").c_str());
    }
    else
    {
        cout << "Unable to open file";
    }
}

void SparseMatrix::printAssetsByDepartment(string department)
{
    SparseMatrixNode *departmentNode = searchColumn(department);
    string content = "";

    if (departmentNode != nullptr)
    {
        SparseMatrixNode *auxiliaryNode = departmentNode->getDownNode();

        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getUserList() != nullptr)
            {
                content += auxiliaryNode->getUserList()->printAssets(auxiliaryNode->getXDepartment(), auxiliaryNode->getYCorporation());
            }
            auxiliaryNode = auxiliaryNode->getDownNode();
        }
    }
    generateReport(department, content);
}

void SparseMatrix::printAssetsByCorporation(string corporation)
{
    SparseMatrixNode *departmentNode = searchRow(corporation);
    string content = "";

    if (departmentNode != nullptr)
    {
        SparseMatrixNode *auxiliaryNode = departmentNode->getNextNode();

        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getUserList() != nullptr)
            {
                content += auxiliaryNode->getUserList()->printAssets(auxiliaryNode->getXDepartment(), auxiliaryNode->getYCorporation());
            }
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
    }
    generateReport(corporation, content);
}

void SparseMatrix::printCatalogue(string nickName, string password)
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
                auxiliaryNode->getUserList()->readStartNodes(nickName, password);
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
                myfile << "R" << replaceSpaces(rowHeaders->getYCorporation());
                myfile << "[label = \"" << rowHeaders->getYCorporation() << "\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque, group = 1 ];";
                rowHeaders = rowHeaders->getDownNode();
            }

            rowHeaders = root->getDownNode();
            while (rowHeaders->getDownNode() != nullptr)
            {
                myfile << "R" << replaceSpaces(rowHeaders->getYCorporation()) << "-> R" << replaceSpaces(rowHeaders->getDownNode()->getYCorporation()) << ";";
                rowHeaders = rowHeaders->getDownNode();
            }

            while (columnHeaders != nullptr)
            {
                myfile << "C" << replaceSpaces(columnHeaders->getXDepartment());
                myfile << "[label = \"" << columnHeaders->getXDepartment() << "\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque, group =" << replaceSpaces(columnHeaders->getXDepartment()) + "2"
                       << "];";
                columnHeaders = columnHeaders->getNextNode();
            }

            columnHeaders = root->getNextNode();
            while (columnHeaders->getNextNode() != nullptr)
            {
                myfile << "C" << replaceSpaces(columnHeaders->getXDepartment()) << "-> C" << replaceSpaces(columnHeaders->getNextNode()->getXDepartment()) << ";";
                columnHeaders = columnHeaders->getNextNode();
            }

            myfile << "Mt -> R" << replaceSpaces(root->getDownNode()->getYCorporation()) << ";";
            myfile << "Mt -> C" << replaceSpaces(root->getNextNode()->getXDepartment()) << ";";

            myfile << "{ rank = same; Mt;";
            columnHeaders = root->getNextNode();
            while (columnHeaders != nullptr)
            {
                myfile << "C" << replaceSpaces(columnHeaders->getXDepartment()) << ";";
                columnHeaders = columnHeaders->getNextNode();
            }
            myfile << "}";

            while (auxiliaryRow != nullptr)
            {
                auxiliaryNode = auxiliaryRow->getNextNode();
                while (auxiliaryNode != nullptr)
                {
                    myfile << "C" << replaceSpaces(auxiliaryNode->getXDepartment());
                    myfile << "R" << replaceSpaces(auxiliaryNode->getYCorporation());
                    myfile << " [label = \"" << auxiliaryNode->getUserList()->getFirstNode()->getUser()->getNickname() << "\" width = 1.5,";
                    //
                    auxiliaryNode->getUserList()->report(auxiliaryNode->getXDepartment(), auxiliaryNode->getYCorporation());
                    //
                    myfile << " style = filled, fillcolor = cornsilk2,";
                    myfile << " group = " << replaceSpaces(auxiliaryNode->getXDepartment()) + "2"
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
                        myfile << "R" << replaceSpaces(auxiliaryNode->getYCorporation());
                    }
                    else
                    {
                        myfile << "C" << replaceSpaces(auxiliaryNode->getXDepartment());
                        myfile << "R" << replaceSpaces(auxiliaryNode->getYCorporation());
                    }
                    myfile << " -> C" << replaceSpaces(auxiliaryNode->getNextNode()->getXDepartment());
                    myfile << "R" << replaceSpaces(auxiliaryNode->getNextNode()->getYCorporation()) << " [dir=\"both\"];";
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }

                myfile << "{ rank = same; ";
                auxiliaryNode = auxiliaryRow;
                while (auxiliaryNode != nullptr)
                {
                    if (auxiliaryNode->getXDepartment() == "-1")
                    {
                        myfile << " R" << replaceSpaces(auxiliaryNode->getYCorporation()) << ";";
                    }
                    else
                    {
                        myfile << " C" << replaceSpaces(auxiliaryNode->getXDepartment());
                        myfile << "R" << replaceSpaces(auxiliaryNode->getYCorporation()) << ";";
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
                        myfile << "C" << replaceSpaces(auxiliaryNode->getXDepartment());
                    }
                    else
                    {
                        myfile << "C" << replaceSpaces(auxiliaryNode->getXDepartment());
                        myfile << "R" << replaceSpaces(auxiliaryNode->getYCorporation());
                    }
                    myfile << " -> C" << replaceSpaces(auxiliaryNode->getDownNode()->getXDepartment());
                    myfile << "R" << replaceSpaces(auxiliaryNode->getDownNode()->getYCorporation()) << " [dir=\"both\"];";
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
