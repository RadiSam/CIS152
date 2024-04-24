#include<reportnodes.h>

//constructors&destructor
ReportNodes::ReportNodes() {
    moneySpent = 0;
    chancesSpent = 0;
    moneyEarned = 0;
    round = 0;
    plinkoResult = "N/A";
    rouletteResult = "N/A";
    next = nullptr;
}
ReportNodes::ReportNodes(int round) {
    moneySpent = 0;
    chancesSpent = 0;
    moneyEarned = 0;
    this->round = round;
    plinkoResult = "N/A";
    rouletteResult = "N/A";
    next = nullptr;
}
ReportNodes::~ReportNodes() {}

//setters
void ReportNodes::setRound(int currRound) {
    round = currRound;
}
void ReportNodes::setMoneySpent(int money) {
    moneySpent = money;
}
void ReportNodes::setChancesSpent(int chances) {
    chancesSpent = chances;
}
void ReportNodes::setMoneyEarned(int money) {
    moneyEarned = money;
}
void ReportNodes::setPResult(string result) {
    plinkoResult = result;
}
void ReportNodes::setRResult(string result) {
    rouletteResult = result;
}
void ReportNodes::setNext(ReportNodes *nextNode) {
    next = nextNode;
}

//getters
int ReportNodes::getRound() const {
    return round;
}
int ReportNodes::getMoneySpent() const{
    return moneySpent;
}
int ReportNodes::getChancesSpent() const{
    return chancesSpent;
}
int ReportNodes::getMoneyEarned() const{
    return moneyEarned;
}
string ReportNodes::getPResult() const {
    return plinkoResult;
}
string ReportNodes::getRResult() const {
    return rouletteResult;
}
ReportNodes* ReportNodes::getNext() const {
    return next;
}

