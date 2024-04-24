#ifndef STORE_H
#define STORE_H
#include <player.h>
#include <report.h>
#include <iostream>

class Store {
private:
    //holds how many chances bought
    int chances;
    //holds how much paid
    int bank;
public:
    Store();
    ~Store();
    //setters
    void setChances(int chancesBought);
    void setBank(int moneySpent);
    //getters
    int getChances() const;
    int getBank() const;
    //allows player to buy and updates info
    void buyStuff(Player &name, ReportNodes* node);

};

#endif // STORE_H
