#ifndef ROULETTE_H
#define ROULETTE_H
#include <queue>
#include <string>
#include <player.h>
#include <reportnodes.h>
using namespace std;

class Roulette {
private:
    //holds prize amounts
    queue<int> roulette;
public:
    //constructors&destructor
    Roulette();
    Roulette(int size);
    ~Roulette();
    //sets queue with random numbers
    void setQueue(int size);
    //returns string of gamble results and updates info
    string getResult(int chances, Player& player, ReportNodes* node);
    //checks roulette inbound condition
    bool queueAvailable(int chances, queue<int> wheel);
    //returns queue
    queue<int> getWheel();
};

#endif // ROULETTE_H
