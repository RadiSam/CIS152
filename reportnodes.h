#ifndef REPORTNODES_H
#define REPORTNODES_H

// Node class for linkedlist of reports
class ReportNodes {
private:
    //records stats listed
    int round;
    int moneySpent;
    int chancesSpent;
    int moneyEarned;
    ReportNodes* next;
public:
    ReportNodes();
    ~ReportNodes();
    //setters
    void setMoneySpent(int money);
    void setChancesSpent(int chances);
    void setMoneyEarned(int money);
    void setNext(ReportNodes* nextNode);
    void setRound(int currRound);
    //getters
    int getMoneySpent() const;
    int getChancesSpent() const;
    int getMoneyEarned() const;
    ReportNodes* getNext() const;
    int getRound() const;

};

#endif // REPORTNODES_H
