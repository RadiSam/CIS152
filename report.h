#ifndef REPORT_H
#define REPORT_H
#include<reportnodes.h>
#include<string>
using namespace std;

// report class that uses a linkedlist to store various action and stats from player
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
    // if not empty, traverses through linkedlist nodes and returns string TODO
    string printList(ReportNodes* node);
    // takes Node and makes it head while updating size
    void insert(ReportNodes* node);
    // traverses through linkedlist nodes searching for object that matches and is used for remove function
    ReportNodes* search(int round);
    // when not empty, uses search function to compare objects in list to find round node and removes it
    void remove(int round);
    // getter for head
    ReportNodes* getHead() const;
};

#endif // REPORT_H
