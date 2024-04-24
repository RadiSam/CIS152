#ifndef REPORT_H
#define REPORT_H
#include <reportnodes.h>
#include <string>
#include <vector>
using namespace std;

// report class that uses a linkedlist to store various actions and stats from player
class Report {
private:
    int size; // size holds how many reports currently held
    ReportNodes* head; // Head of linkedlist
    ReportNodes* tail; // tail of linkedlist
public:
    // constructor and deconstructor
    Report();
    ~Report();
    // returns true when size is 0
    bool isEmpty();
    // returns head address of linked list when not empty
    ReportNodes* peek();
    // returns size
    int Size();
    // returns head node
    ReportNodes* getHead() const;
    // takes Node and makes it head while updating size
    void insert(ReportNodes* node);
    // when not empty, uses search function to compare objects in list to find round node and remove it
    void remove(int round);
    // traverses through linkedlist nodes searching for object that matches and is used for remove function
    ReportNodes* search(int round);
    // searches for node and returns non-ptr object
    ReportNodes searchConversion(int round);
    // insertion sort from lowest to highest value that takes vector of reportNodes, sizeof report and returns it
    vector<ReportNodes> insertionSort(vector<ReportNodes> report, int n);
    // if not empty, traverses through linkedlist nodes and returns string in chronological order of rounds
    string printList(int roundTill);
    //prints based on money earned from lowest to highest
    string printEarnedLtoH(int roundTill);
    //prints single node
    string printNode(ReportNodes* node);
    //overloaded for nonptr node
    string printNode(ReportNodes node);
};

#endif // REPORT_H
