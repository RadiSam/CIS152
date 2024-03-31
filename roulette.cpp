#include<roulette.h>
#include<queue>
#include<ctime>
#include<cstdlib>

//constructors&destructor
Roulette::Roulette() {
    roulette = setQueue(20);
}

Roulette::Roulette(int size) {
    roulette = setQueue(size);
}
Roulette::~Roulette() {}

// returns queue of random ints when given size int
queue<int> Roulette::setQueue(int size) {
    srand(time(0));
    queue<int> prizes;

    for (int i = 0; i < size; i++) {
        int prize = (rand() % 100) + 1;
        prizes.push(prize);
    }
    return prizes;
}

// returns string of results, roulette start funct
string Roulette::getResult(int chances) {
    string result = "Here is the result of your luck!\n";

    for (int i = 0; i < chances; i++) {
        result.append(to_string(roulette.front()) + " ");
        roulette.pop();
    }

    return result;
}
