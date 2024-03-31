#ifndef STORE_H
#define STORE_H
#include <player.h>
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
    //getters
    int getChances();
    int getBank();
    //allows player to buy
    void buyStuff(Player &name);

};

#endif // STORE_H
