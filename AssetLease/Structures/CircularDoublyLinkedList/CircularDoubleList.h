#ifndef CIRCULARDOUBLELIST_H
#define CIRCULARDOUBLELIST_H

#include <iostream>
#include <fstream>
#include "CircularDoubleNode.h"
using namespace std;

class CircularDoubleList
{
private:
    CircularDoubleNode *firstNode;
    CircularDoubleNode *lastNode;
    bool isEmpty();

public:
    CircularDoubleList();
    ~CircularDoubleList();

    void addNode(Lease *lease);
    void readStartNodes();
    void deleteSpecificNode(string identifier);
    CircularDoubleNode *searchNode(string identifier);
    void report();
};

#endif // CIRCULARDOUBLELIST_H
