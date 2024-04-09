#include<report.h>

// constructor&destructor
Report::Report() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}
Report::~Report() {}

// returns true when size is 0
bool Report::isEmpty() {
    return size == 0;
}

// returns head address of linked list when not empty
ReportNodes* Report::peek() {
    if (!isEmpty()) {
        return head;
    }
    return nullptr;
}

// returns size
    int Report::Size() {
        return size;
    }
    // if not empty, traverses through linkedlist nodes and returns string TODO
    string Report::printList(ReportNodes* node) {
        string result = "";
        result.append(to_string(node->getMoneySpent()));
        return result;
    }
    // takes Node and makes it head while updating size
    void Report::insert(ReportNodes* node) {
        node->setNext(head);
        head = node;
        size++;
    }
    // traverses through linkedlist nodes searching for object that matches and is used for remove function
    ReportNodes* Report::search(int round) {
        if (!isEmpty()) {
            ReportNodes* temp = head;
            while ((temp != NULL) && (temp->getRound() != round)) {
                temp = temp->getNext();
            }
            return temp;
        }
        return nullptr;
    }
    // when not empty, uses search function to compare objects in list to find round node and removes it
    void Report::remove(int round) {
        if (!isEmpty()) {
            ReportNodes* temp = search((round));
            ReportNodes* temphead = head;
            if(temphead == temp) { // case when head object is object needed to be removed
                temphead->setNext(temp->getNext());
                size--;
            }
            else {// loops through to find matched address
                while (temphead->getNext() != temp) {
                    temphead = temphead->getNext();
                }
                // changes headptr to point to object after 'removed' object and decrements size
                temphead->setNext(temp->getNext());
                size--;
            }
        }
    }
    // getter for head
    ReportNodes* Report::getHead() const {
        return head;
    }
