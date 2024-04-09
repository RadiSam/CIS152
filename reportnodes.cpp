#include<reportnodes.h>

//constructor&destructor
ReportNodes::ReportNodes() {
    moneySpent = 0;
    chancesSpent = 0;
    moneyEarned = 0;
    next = nullptr;
}
ReportNodes::~ReportNodes() {}

//getters
int ReportNodes::getMoneySpent() const{
    return moneySpent;
}
int ReportNodes::getChancesSpent() const{
    return chancesSpent;
}
int ReportNodes::getMoneyEarned() const{
    return moneyEarned;
}
ReportNodes* ReportNodes::getNext() const {
    return next;
}
int ReportNodes::getRound() const {
    return round;
}
//setters
void ReportNodes::setMoneySpent(int money) {
    moneySpent = money;
}
void ReportNodes::setChancesSpent(int chances) {
    chancesSpent = chances;
}
void ReportNodes::setMoneyEarned(int money) {
    moneyEarned = money;
}
void ReportNodes::setNext(ReportNodes *nextNode) {
    next = nextNode;
}
void ReportNodes::setRound(int currRound) {
    round = currRound;
}
