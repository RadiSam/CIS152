#ifndef REPORTNODES_H
#define REPORTNODES_H
#include <string>
using namespace std;

// Node class for linkedlist of reports
class ReportNodes {
private:
    //records stats listed
    int round;
    int moneySpent;
    int chancesSpent;
    int moneyEarned;
    string plinkoResult;
    string rouletteResult;
    ReportNodes* next;
public:
    //constructors&destructor
    ReportNodes();
    ReportNodes(int round);
    ~ReportNodes();
    //setters
    void setRound(int currRound);
    void setMoneySpent(int money);
    void setChancesSpent(int chances);
    void setMoneyEarned(int money);
    void setPResult(string result);
    void setRResult(string result);
    void setNext(ReportNodes* nextNode);
    //getters
    int getRound() const;
    int getMoneySpent() const;
    int getChancesSpent() const;
    int getMoneyEarned() const;
    string getPResult() const;
    string getRResult() const;
    ReportNodes* getNext() const;
};

#endif // REPORTNODES_H
