#include<roulette.h>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<iostream>

//constructors&destructor
Roulette::Roulette() {
    setQueue(20);
}
Roulette::Roulette(int size) {
    setQueue(size);
}
Roulette::~Roulette() {}

// sets queue with given size of random ints with max of size
void Roulette::setQueue(int size) {
    srand(time(0));
    queue<int> prizes;
    for (int i = 0; i < size; i++) {
        int prize = (rand() % size) + 1;
        prizes.push(prize);
    }
    roulette = prizes;
}

// returns string of results, also starts the roulette
string Roulette::getResult(int chances, Player& player, ReportNodes* node) {
    string result = "Here is the result of your luck!\n";
    int totalEarned = 0;
    //nothing happens when input is 0
    if (chances == 0) {return "Looks like nothing was entered.";}
    //plays roulette
    for (int i = 0; i < chances; i++) {
        result.append(to_string(roulette.front()) + " ");
        totalEarned += roulette.front();
        roulette.pop();
    }
    //updates info
    player.setPocket(player.getPocket() + totalEarned);
    node->setMoneyEarned(node->getMoneyEarned() + totalEarned);
    node->setRResult(result.substr(33, result.size()));
    return result;
}

// returns true when chances is less than or equal to wheel size
bool Roulette::queueAvailable(int chances, queue<int> wheel) {
    int wheelSize = wheel.size();
    if (chances > wheelSize) {
        cout << "Woah hold on, that's too many chances the wheel can handle." <<
            " Try again with a smaller amount next time(Max is 20)." << endl;
        return false;
    }
    else {
        return true;
    }
}
//returns wheel
queue<int> Roulette::getWheel() {
    return roulette;
}
