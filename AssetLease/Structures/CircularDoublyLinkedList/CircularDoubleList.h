#ifndef CIRCULARDOUBLELIST_H
#define CIRCULARDOUBLELIST_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include "CircularDoubleNode.h"
using namespace std;

class CircularDoubleList
{
private:
    static CircularDoubleList *instance;
    CircularDoubleNode *firstNode;
    CircularDoubleNode *lastNode;
    CircularDoubleList();
    bool isEmpty();

public:
    static CircularDoubleList *getInstance();
    ~CircularDoubleList();

    void addNode(Lease *lease);
    void readStartNodes(User *user);
    void deleteSpecificNode(string identifier);
    CircularDoubleNode *searchNode(string identifier);
    void report();
    void report(string department, string corporation, string user);
    void sortAscending();
    void sortDescending();
};

#endif // CIRCULARDOUBLELIST_H
