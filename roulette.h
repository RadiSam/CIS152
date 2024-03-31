#ifndef ROULETTE_H
#define ROULETTE_H
#include <queue>
#include <string>
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
    //sets queue
    queue<int> setQueue(int size);
    //returns results of gamble
    string getResult(int chances);
};

#endif // ROULETTE_H
