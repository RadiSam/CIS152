#include<report.h>

// constructor&destructor
// creates only ten round space
Report::Report() {
    size = 0;
    head = nullptr;
    tail = nullptr;
    ReportNodes* r1 = new ReportNodes(1);
    ReportNodes* r2 = new ReportNodes(2);
    ReportNodes* r3 = new ReportNodes(3);
    ReportNodes* r4 = new ReportNodes(4);
    ReportNodes* r5 = new ReportNodes(5);
    ReportNodes* r6 = new ReportNodes(6);
    ReportNodes* r7 = new ReportNodes(7);
    ReportNodes* r8 = new ReportNodes(8);
    ReportNodes* r9 = new ReportNodes(9);
    ReportNodes* r10 = new ReportNodes(10);
    insert(r1);
    insert(r2);
    insert(r3);
    insert(r4);
    insert(r5);
    insert(r6);
    insert(r7);
    insert(r8);
    insert(r9);
    insert(r10);
}
Report::~Report() {}

// returns true when size is 0
bool Report::isEmpty() {
    return size == 0;
}
// returns head node of linked list when not empty
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
// returns head node
ReportNodes* Report::getHead() const {
    return head;
}
// takes Node and makes it head while updating size
void Report::insert(ReportNodes* node) {
    node->setNext(head);
    head = node;
    size++;
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
        else {// loops through to find matched node
            while (temphead->getNext() != temp) {
                temphead = temphead->getNext();
            }
            // changes headptr to point to object after 'removed' object and decrements size
            temphead->setNext(temp->getNext());
            size--;
        }
    }
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
// searches for node and returns non-ptr object
ReportNodes Report::searchConversion(int round) {
    ReportNodes tempNode;
    if (!isEmpty()) {
        ReportNodes* temp = head;
        while ((temp != NULL) && (temp->getRound() != round)) {
            temp = temp->getNext();
        }
        //sets values of node object
        if (temp != nullptr) {
            tempNode.setChancesSpent(temp->getChancesSpent());
            tempNode.setMoneyEarned(temp->getMoneyEarned());
            tempNode.setMoneySpent(temp->getMoneySpent());
            tempNode.setNext(temp->getNext());
            tempNode.setRound(temp->getRound());
            tempNode.setPResult(temp->getPResult());
            tempNode.setRResult(temp->getRResult());
        }
    }
    return tempNode;
}
// insertion sort from lowest to highest moneyEarned value that takes vector of reportNodes and returns it sorted
vector<ReportNodes> Report::insertionSort(vector<ReportNodes> report, int n) {
    int i, key, j;
    ReportNodes keyNode;
    for (i = 1; i < n; i++) {
        key = report.at(i).getMoneyEarned();
        keyNode = report.at(i);
        j = i - 1;
        while (j >= 0 && report.at(j).getMoneyEarned() > key) {
            report.at(j+1) = report.at(j);
            j -= 1;
        }
        report.at(j+1) = keyNode;
    }
    return report;
}
// returns string of reports in chronological order
string Report::printList(int roundTill) {
    if (!isEmpty()) {
        string result = "";
        //searches for node and appends node report
        for (int i = 1; i < roundTill; i++) {
            result.append(printNode(search(i)));
        }
        return result;
    }
    return "There doesn't seem to be any information available";
}
// returns string report based on money earned from lowest to highest
string Report::printEarnedLtoH(int roundTill) {
    unsigned int i;
    if (!isEmpty()) {
        string result = "";
        vector<ReportNodes> tempVect;
        // adds converted nodeptrs to vector
        for (int i = 1; i < roundTill; i++) {
            ReportNodes tempNode = searchConversion(i);
            tempVect.push_back(tempNode);
        }
        // sorts vector and appends node report
        tempVect = insertionSort(tempVect, tempVect.size());
        for (i = 0; i < tempVect.size(); i++) {
            result.append(printNode(tempVect.at(i)));
        }
        return result;
    }
    return "There doesn't seem to be any information available";
}
// prints single node info in report format
string Report::printNode(ReportNodes* node) {
    string result = "\nRound: ";
    result.append(to_string(node->getRound()) + "\nChances Spent: ");
    result.append(to_string(node->getChancesSpent()) + "\nMoney Earned: ");
    result.append(to_string(node->getMoneyEarned()) + "\nMoney Spent: ");
    result.append(to_string(node->getMoneySpent()));
    if (node->getPResult() != "N/A") {
        result.append("\nPlinko result: " + node->getPResult());
    }
    if (node->getRResult() != "N/A") {
        result.append("\nRoulette result: " + node->getRResult());
    }
    return result;
}
// overloaded for nonptr node
string Report::printNode(ReportNodes node) {
    string result = "\nRound: ";
    result.append(to_string(node.getRound()) + "\nChances Spent: ");
    result.append(to_string(node.getChancesSpent()) + "\nMoney Earned: ");
    result.append(to_string(node.getMoneyEarned()) + "\nMoney Spent: ");
    result.append(to_string(node.getMoneySpent()));
    if (node.getPResult() != "N/A") {
        result.append("\nPlinko result: " + node.getPResult());
    }
    if (node.getRResult() != "N/A") {
        result.append("\nRoulette result: " + node.getRResult());
    }
    return result;
}
